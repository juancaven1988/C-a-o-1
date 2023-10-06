#include<stdio.h>
#include "boolean.h"


void bscan (boolean &x){

char opc;

do{
fflush(stdin);
printf("Ingrese el valor booleano:\n");
printf("F - FALSE    T - TRUE\n");
scanf("%c", &opc);

if (opc != 'F' && opc != 'T' && opc != 'f' && opc != 't')
	printf("ERROR - valor no valido\n");

}while (opc != 'F' && opc != 'T' && opc != 'f' && opc != 't');

if (opc == 'F' || opc == 'f')
	x = FALSE;
else
	x = TRUE;
}


void bprint (boolean x){

if (x == FALSE)
	printf("El valor es FALSO\n");
else
	printf("El valor es TRUE\n");


}

