#include "unistd.h"
#include <stdio.h>
#include "io.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"


void Affiche_Config (int position, int numero_afficheur){
	//HELLO 2019
	unsigned char Texte[] = {0x76,0x79,0x38,0x38,0x3F,0x0,0x5B,0x3F,0x06,0x6F};
	if( numero_afficheur < 6){
		IOWR(IP7SEG_BASE, numero_afficheur, Texte[position]);
	}
}

void Test_Affiche_Config(void){
	int i, j, k;
	i = j = k = 0;

		for(k=0;k<16;k++)
		{
			j=0;
			SEG7_Clear(IP7SEG_BASE,6);
			for(i=k ; i>=0 ; i--){
				if(j>(10-1)){
					IOWR(IP7SEG_BASE, i, 0x0);
				}
				else
				{
					Affiche_Config(j,i);
				}
				j++;
			}
			usleep(500000);
		}
}

void irq_Affiche_Message(){

	IOWR(IP_BP1_BASE, 3, 0x0);	//Clear les IT au niveau du composant
	IOWR(IP_BP1_IRQ, 3, 0x0);  // acquitter l'IT
	Test_Affiche_Config();
}





void InitItBP1(void){
	//Initialisation au niveau du composant: IP_BP1
	IOWR(IP_BP1_BASE, 2, 0x1);		//IRQ enable/disable for each input port. Setting a bit to 1 enables interrupts for the corresponding port.
	IOWR(IP_BP1_BASE, 3, 0x0);		//Nettois d'eventuelle IRQ encore pr�sentent sur le composant

	//Initialisation au niveau du �P
	alt_irq_register( IP_BP1_IRQ, 0, irq_Affiche_Message);
}

