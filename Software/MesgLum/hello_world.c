/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "seg7_if.h"
#include "system.h"
#include "unistd.h"
#include "seg7driv.h"


void Test2019(void);
void Test2(void);


int main()
{
	InitItBP1();
	int i = 0;

	printf("Hello from Paulo\n");
  //Test2();
	SEG7_Clear(IP7SEG_BASE,6);
//  Affiche_Config(0,2);
//  Affiche_Config(1,3);
//  Affiche_Config(2,4);
//  Affiche_Config(3,5);
//  Affiche_Config(4,6);

	//Test_Affiche_Config();
	while(1){
		printf(".");
		fflush(stdout);
		usleep(300000);
		if(++i > 100){
			printf("\n");
			i=0;
		}
	};

  return 0;
}


void Test2019(){
	static    unsigned char szMap[] = {
	        63, 6, 91, 79, 102, 109, 125, 7,
	        127, 111, 119, 124, 57, 94, 121, 113
	    };  // 0,1,2,....9, a, b, c, d, e, f

	  //SEG7_Number(IP7SEG_BASE, 4);
		IOWR(IP7SEG_BASE, 0, szMap[9]);
		IOWR(IP7SEG_BASE, 1, szMap[1]);
		IOWR(IP7SEG_BASE, 2, szMap[0]);
		IOWR(IP7SEG_BASE, 3, szMap[2]);
		IOWR(IP7SEG_BASE, 4, 0);
		IOWR(IP7SEG_BASE, 5, 3);
}


void Test2(){
							//HELLO 2019
	unsigned char Texte[] = {0x76,0x79,0x38,0x38,0x3F,0x0,0x5B,0x3F,0x06,0x6F};
	for (int i=0; i<6;i++)
	{
		IOWR(IP7SEG_BASE, (5-i), Texte[i]);
	}

}
