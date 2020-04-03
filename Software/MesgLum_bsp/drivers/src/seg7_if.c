
#include "seg7_if.h"

static    unsigned char szMap[] = {
        63, 6, 91, 79, 102, 109, 125, 7, 
        127, 111, 119, 124, 57, 94, 121, 113
    };  // 0,1,2,....9, a, b, c, d, e, f
    
void SEG7_Clear(alt_u32 base, alt_u8 num_seg7){
    int i;
    for(i=0;i<num_seg7;i++){
        IOWR(base, i, 0x00);
    }        
}
void SEG7_Full(alt_u32 base, alt_u8 num_seg7){
    int i;
    for(i=0;i<num_seg7;i++){
    	IOWR(base, i, 0xFF);
    }        
}

void SEG7_Number(alt_u32 base, alt_u8 num_seg7){
    int i;
    for(i=0;i<num_seg7;i++){
    	IOWR(base, i, szMap[i]);
    }        
}

void SEG7_Hex(alt_u32 base, alt_u32 data, alt_u8 num_seg7){
    alt_u8 mask = 0x01;
    alt_u8 seg_mask;
    int i;
    
    //
    seg_mask = 0;
    for(i=0;i<num_seg7;i++){
        seg_mask = szMap[data & 0x0F];
        data >>= 4;
        mask <<= 1;     
        IOWR(base, i, seg_mask);
    }        
}

void SEG7_Decimal(alt_u32 base, alt_u32 data, alt_u8 num_seg7){
    alt_u8 mask = 0x01;
    alt_u8 seg_mask;
    int i;
    
    //
    seg_mask = 0;
    for(i=0;i<num_seg7;i++){
        seg_mask = szMap[data%10];
        data /= 10;
        mask <<= 1;   
        IOWR(base, i, seg_mask);
    }        
  
} 

