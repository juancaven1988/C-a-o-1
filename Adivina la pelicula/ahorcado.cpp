#include "ahorcado.h"

void crear_espacios (cadenas pelicula, cadenas &adivinanza){
   int i = 0;
   char c;

   while(i < TAM -1 && pelicula[i] != '\0'){
       c = pelicula[i];
        if(c != ' ')
         adivinanza[i] = '-';
       else
        adivinanza[i] = ' ';
    i++;

    }

      adivinanza[i] = '\0';
      }


void generar_intentos (int &intentos){

        printf("Jugador 1 ingrese el numero de intentos maximos (entre 4 y 8): ");
		scanf("%d", &intentos);

    while ( intentos < 4 || intentos > 8 ){
            printf("El numero de intentos debe ser entre 4 y 8\n Ingrese un valor valido: ");
            scanf("%d", &intentos);}



}


void crear_errores (cadenas &errores, int intentos){

  for (int i = 0; i <= intentos; i++)
  errores[i] = ' ';

  errores[intentos+1] = '\0';

}

boolean chekadv (cadenas adivinanza){

    boolean existe = FALSE;
    int i= 0;
do{

    if (adivinanza[i] == '-')
         existe = TRUE;
    else
        i++;
    }while (!existe && adivinanza[i] !='\0');

return existe;}

boolean colocarletra (cadenas pelicula,  cadenas &adivinanza, char c){

boolean existe = FALSE;

          for (int i = 0; pelicula[i] != '\0'; i++){

               if (pelicula[i] == c || pelicula[i] == c - 32 ){
                      adivinanza[i] = pelicula[i];
                      existe = TRUE;}
           }

return existe;}


