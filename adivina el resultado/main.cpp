#include <stdio.h>
#include <stdlib.h>
#include <ctime>

/* dados dos sumandos  aleatorio y un resultado comprobar si el resultado es correcto*/


int main()
{

    srand(time(NULL));

   int sumando1, sumando2, resultado, puntaje;

   puntaje = 0;


          sumando1 = 1 + rand()%(99-1);  /* Generar numero aleatorio entre 1- 99 */
          sumando2 = rand()%99;          /* genera numero random entre 0 - 99 */

          printf("Ingresa el resultado correto\n");
          printf("%d + %d= ", sumando1, sumando2); /*expresar los numeros generados y solicitar un resultado */
          scanf("%d", &resultado);

          /*Controlar si el resultado es correcto y asignar puntaje */
                    if (resultado == sumando1 + sumando2){
                        printf("******\n*BIEN*\n******\n", ++puntaje);
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }

                    else{
                        printf("*****\n*MAL*\n*****\n");
                        printf ("*************\n*Puntaje: %d *\n*************\n", puntaje);
                        }




      /*repetir el proceso anterior hasta que el puntaje sea 10*/

          while (puntaje<10){

          sumando1 = rand()%99;
          sumando2 = rand()%99;
          printf("Ingresa el resultado correto\n");
          printf("%d + %d= ", sumando1, sumando2); /*expresar los numeros generados y solicitar un resultado */
          scanf("%d", &resultado);

          /*Controlar si el resultado es correcto y asignar puntaje */
                    if (resultado == sumando1 + sumando2){
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
