#include <stdio.h>
#include <stdlib.h>

const int VENDEDORES = 4;
const int PRODUCTOS = 5;

int main(){


int ventas_mes [PRODUCTOS][VENDEDORES];
int vendedor, producto, ventas, total_product, total_vend;


for (int i = 0; i < PRODUCTOS; i++){
    for (int j = 0; j < VENDEDORES; j++)
         ventas_mes [i][j] = 0;}



for (int dia = 1; dia < 31; dia++){

    printf("Dia %d del mes\n", dia);
    do{

        printf("Ingrese numero de vendedor (-1 pasa al siguiente dia): ");
        scanf("%d", &vendedor);
        if(vendedor != -1){
                do{
                printf("Ingrese el producto vendido: ");
                scanf("%d", &producto);
                if (producto <= 0 || producto > PRODUCTOS)
                    printf("ERROR PRODUCTO INEXISTENTE\n");
                }while(producto <= 0 || producto > PRODUCTOS);

                printf("Ingrese el total vendido: ");
                scanf("%d", &ventas);}

        if (vendedor <= VENDEDORES && vendedor > 0)
            ventas_mes[producto -1][vendedor-1] = ventas_mes[producto -1][vendedor-1] + ventas;


    }while (vendedor > 0 && vendedor <= VENDEDORES);



}

 system("cls");

printf("\tVENTAS TOTALES DEL MES\n");

printf("Vendedor     ");

for(int i = 0; i <VENDEDORES; i++)
    printf("%5d   ", i+1);

    printf("\tTOTAL");
    printf("\n");

for (int i = 0; i < PRODUCTOS; i++){
        printf("Producto %d - ", i+1);
        total_product = 0;
    for (int j = 0; j < VENDEDORES; j++){
         printf("%5d - ", ventas_mes [i][j]);
           total_product = total_product + ventas_mes [i][j];}

   printf("%5d\n", total_product);

}


printf("TOTAL        ");

for (int i = 0; i < VENDEDORES; i++){

    total_vend = 0;

       for (int j = 0; j < PRODUCTOS; j++)
             total_vend = total_vend + ventas_mes [j][i];

   printf("%5d   ", total_vend);
}


}
