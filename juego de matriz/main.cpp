#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 4;



int main()
{
    srand(time(NULL));

    int mat[0][0];

    int i, j, opcion;

    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++)
        mat[i][j] = 1 + rand() % 9;
    }

     for(i = 0; i < N; i++){
        for (j = 0; j < N; j++)
           printf("%d ",mat[i][j]);
        printf("\n");
    }
do{
  printf("\nPor favor elija una opcion de las siguientes:\n");
  printf("\t1: Calcular la suma de los valores de la fila superior y la columna izquierda\n");
  printf("\t2: Obtener la diferencia entre la suma de los elementos de la diagonal principal y la secundaria\n");
  printf("\t3: Calcular el promedio de los elementos del rectangulo superior\n");
  printf("\t4: Invertir la matriz\n");
  printf("\t-1: Finalizar.\n");

  scanf("%d", &opcion);

   switch (opcion){

   case 1: {int suma = mat[0][0];

           for (i = 1; i < N; i++)
           suma = suma + mat[0][i] + mat[i][0];

           printf("\nLa suma de la fila superior y columna izquierda es: %d", suma);

           break;}

   case 2:{ int dif = 0;

         for (i = 0; i < N; i++)
              dif = dif + mat[i][i] - mat [N-1-i][i];

         printf("\nLa diferencia entre la diagonal principal y secundaria es: %d", dif);
         break;}
   case 3:{float prom = 0;
           int cont = 0;

        for (i = 0; i < N - i; i++){
          for(j = 0; j < N; j++){
              prom = prom + mat[i][j];
              cont++;}}
       prom = prom /(float)cont;

       printf("\nEl promedio de los elementos del rectangulo superior es: %.2f", prom);
       break;}
   case 4:{
       printf("\n");

        for(i = N-1; i >= 0; i--){
          for (j = 0; j < N; j++)
            printf("%d ",mat[i][j]);
         printf("\n");
      }
          break;
         }
    case -1:printf("Hasta luego\n"); break;
  default: printf("ERROR\nLa opcion elegida no es correcta\n");
  fflush(stdin);
}}while (opcion != -1);

return 0;}
