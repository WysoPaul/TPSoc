#ifndef SEG7_H_
#define SEG7_H_

#include "io.h"
#include "alt_types.h"

void SEG7_Clear(alt_u32 base, alt_u8 num_seg7);
void SEG7_Full(alt_u32 base, alt_u8 num_seg7);
void SEG7_Hex(alt_u32 base, alt_u32 data, alt_u8 num_seg7);
void SEG7_Decimal(alt_u32 base, alt_u32 data, alt_u8 num_seg7);
void SEG7_Number(alt_u32 base, alt_u8 num_seg7);

#define SEG7_IF_INSTANCE(name, dev) extern int alt_no_storage
#define SEG7_IF_INIT(name, dev) while (0)
	
#endif /*SEG7_H_*/
