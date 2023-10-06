#include <stdio.h>
#include <stdlib.h>
#include <ctime>

/* dados dos sumandos  aleatorio y un resultado comprobar si el resultado es correcto*/


int main()
{
    srand(time(NULL));

   int factor1, factor2, producto, puntaje;

   puntaje = 0;


          factor1 = 1 + rand()%(9-1);  /* Generar numero aleatorio entre 1- 9 */
          factor2 = rand()%10;          /* genera numero random entre 0 - 99 */

          printf("Ingresa el resultado correto\n");
          printf("%d x %d= ", factor1, factor2); /*expresar los numeros generados y solicitar un resultado */
          scanf("%d", &producto);

          /*Controlar si el resultado es correcto y asignar puntaje */
                    if (producto == factor1 * factor2){
                        printf("******\n*BIEN*\n******\n", ++puntaje);
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }

                    else{
                        printf("*****\n*MAL*\n*****\n");
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }




      /*repetir el proceso anterior hasta que el puntaje sea 10*/

          while (puntaje<10){

          factor1 = rand()%10;
          factor2 = rand()%10;
          printf("Ingresa el resultado correto\n");
          printf("%d x %d= ", factor1, factor2); /*expresar los numeros generados y solicitar un resultado */
          scanf("%d", &producto);

          /*Controlar si el resultado es correcto y asignar puntaje */
                    if (producto == factor1 * factor2){
                        printf("******\n*BIEN*\n******\n", ++puntaje);
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }

                    else{
                        printf("*****\n*MAL*\n*****\n");
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }




}
        printf("*****************\n* HAS TERMINADO *\n*****************\n");

   return 0;
}
