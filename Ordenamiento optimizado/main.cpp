#include <stdio.h>


const int  SIZE 10;

int main(){

int a[SIZE] = {1, 2,3,4,9,5,6,10,8,7};
int i, pass =1 , hold;
bool intercambio;

printf("El orden inicial es:\n");

for ( i = 0; i < SIZE; i++)
    printf("%d ", a[i]);

printf("\n");


do{    /*pasadas*/

intercambio = false;

    for(i = 0; i < SIZE - pass; i++ ){       /*una pasada */

        if (a[i]> a[i+1]){
            hold = a[i];
            a[i] = a[i+1];
            a[i+1] = hold;
            intercambio = true;}
}

pass++;

}while (pass < SIZE && intercambio);

printf("El arreglo ordenado de forma ascendente es:\n");

for ( i = 0; i < SIZE; i++)
    printf("%d ", a[i]);

printf("\n");

return 0;}
