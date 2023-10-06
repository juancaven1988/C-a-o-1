#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ahorcado.h"



int main()
{
   cadenas pelicula, adivinanza, arriesgar, errores;
   char c;
   int intentos, usados = 0, gamestatus = 0, opc;


/*GAMESTATUS REPRESENTA EL ESTADO DEL JUEGO
0 = NEUTRO, 1 = JUGADOR 2 GANA, 2 = JUGADOR 2 PIERDE */


printf("Jugador 1, ingrese el nombre de una pelicula:\n");

 do{
        scan(pelicula);

        crear_espacios(pelicula, adivinanza);

        if (strlar(pelicula) < 1)
            printf("Debe ingresar al menos una letra:\n");

   }while (strlar(pelicula)<1);

tocap(pelicula);

generar_intentos(intentos);

  fflush(stdin);

crear_errores(errores, intentos);

  printf("\n");

  /*INICIA EL JUEGO */


   do{

        system("cls");

        printf("\n\n");

        printf("Adivine:\n");

        print(adivinanza);

        printf("\n");

        print(errores);

        printf("\n");

        fflush(stdin);

       /* INDICA LOS INTENTOS DISPONIBLES */

        printf("\nJugador 2 tiene %d intentos\n", intentos);
        printf("Sus opciones son:\n");

        do{
            printf("\t1 - Colocar una letra\n\t2 - Intentar adivinar la pelicula\n");
            fflush(stdin);
            scanf("%d", &opc);

            switch(opc){


                /* AQUÍ SE OPTO POR DECIR UNA LETRA Y NO ARRIESGAR */

                case 1: {

                    fflush(stdin);
                    printf("\nIngrese una letra: ");
                    scanf("%c", &c);

                    if(!colocarletra(pelicula,adivinanza,c)){
                    errores[usados] = c;
                    usados++;}
                    intentos --;
                    break;}

                /*EN CASO DE OPTAR POR ADIVINAR LA PELÍCULA */
                case 2:{


                    printf("Ingrese el nombre la pelicula que cree correcta: ");
                    scan(arriesgar);
                    tocap(arriesgar);

                    if (streq(arriesgar, pelicula)){
                    printf("\nFELICIDADES ADIVINASTE\n\n");
                    gamestatus = 1;}
                    else{
                    printf("\nLO SIENTO MUCHO\nPEIRDES\n\n");
                    gamestatus = 2;}

                    break;}

                default: printf("%d no es una opcion valida.\n Por facor ingrese una opcion valida.\n", opc);
                getch();
            }

        }while (opc != 1 && opc != 2);

        if (!chekadv(adivinanza))
        gamestatus = 1;

        if(intentos == 0 && chekadv(adivinanza))
        gamestatus = 2;

    }while (gamestatus == 0);





if (gamestatus == 1){
    printf("\nGana el jugador 2\n");
    printf("La pelicula es : ");

   print (pelicula);

    printf("\n");

    }


else
    {printf("\nGana el jugador 1\nJugador 2 no consiguio adivinar la pelicula\n");
    printf("La pelicula es : ");

  print(pelicula);

    printf("\n");}


}
