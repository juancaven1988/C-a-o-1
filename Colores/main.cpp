#include <stdio.h>
#include <stdlib.h>

const int TAM = 5;

typedef enum {ROJO, NARANJA, AMARILLO, VERDE, CIAN, AZUL,VIOLETA} Colores_arcoiris;

typedef Colores_arcoiris arreglosoblig [TAM];
typedef enum {FALSE, TRUE} boolean;

int main()
{

   arreglosoblig contrasena, intento;
   int i, cont = 0, intentos = 5, lugar = 0, existe = 0;
   char seleccion;
   boolean valido = FALSE;


   printf("Tenemos los colores del arcoiris:\n");
   printf("(R)OJO, (N)ARANJA, (A)MARILLO, (V)ERDE, (C)IAN, AZU(L),V(I)OLETA\n");

   printf("\nCree una secuencia de %d colores, sin importar su orden\n(Puede repetir los colores)\n\n", TAM);

   for (i = 0; i < TAM; i++){
       valido = FALSE;
       while (!valido){
          fflush(stdin);
       printf("Ingrese el color %d: ",i+1);
       scanf("%c", &seleccion);

         switch (seleccion){
         case 'r': case 'R': contrasena[i] = ROJO;
           valido = TRUE;
             break;
         case 'n': case 'N': contrasena[i] = NARANJA;
         valido = TRUE;
             break;
         case 'a':case 'A': contrasena[i] = AMARILLO;
         valido = TRUE;
             break;
         case 'v': case 'V':contrasena[i] = VERDE;
         valido = TRUE;
             break;
         case 'c': case 'C': contrasena[i] = CIAN;
         valido = TRUE;
             break;
         case 'l': case 'L': contrasena[i] = AZUL;
         valido = TRUE;
             break;
         case 'i': case 'I': contrasena[i] = VIOLETA;
         valido = TRUE;
             break;
         default: printf("Color ingresado no valido, favor ingrese un color valido:\n");
          }
         }

   }

   system("cls");


printf("Se ha creado una contrasena de %d colores, tiene %d intentos para adivinarla:\n", TAM, intentos);


while(intentos != 0){

     printf("Tenemos los colores del arcoiris:\n");
     printf("(R)OJO, (N)ARANJA, (A)MARILLO, (V)ERDE, (C)IAN, AZU(L),V(I)OLETA\n");
     printf("Ingrese los 5 colores en el orden que crea puedan ser:\n");

    for (i = 0; i < TAM; i++){
       valido = FALSE;
       while (!valido){
          fflush(stdin);
       printf("Ingrese el color %d: ",i+1);
       scanf("%c", &seleccion);

         switch (seleccion){
         case 'r': case 'R': intento[i] = ROJO;
           valido = TRUE;
             break;
         case 'n': case 'N': intento[i] = NARANJA;
         valido = TRUE;
             break;
         case 'a':case 'A': intento[i] = AMARILLO;
         valido = TRUE;
             break;
         case 'v': case 'V':intento[i] = VERDE;
         valido = TRUE;
             break;
         case 'c': case 'C': intento[i] = CIAN;
         valido = TRUE;
             break;
         case 'l': case 'L': intento[i] = AZUL;
         valido = TRUE;
             break;
         case 'i': case 'I': intento[i] = VIOLETA;
         valido = TRUE;
             break;
         default: printf("Color ingresado no valido, favor ingrese un color valido:\n");
          }
         }

   }

lugar = 0;
existe = 0;
int guardar[TAM] = {5} ;
    boolean esta = FALSE;


    for (int i = 0; i < TAM; i++){
        if (contrasena[i] == intento[i]){
            lugar++;
            guardar[i] = i;}
    }


 int i = 0;

 do{
  boolean comprobar = TRUE;

  int j = 0;

 for (int n = 0; n < i; n++)
    if (intento[n] == intento[i])
            comprobar = FALSE;
 if (comprobar){
   do{
    if (intento[i] == contrasena[j])
     esta = TRUE;
    else
        j++;

   }while(esta == FALSE && j <TAM);}

  i++;

  if (esta){
    existe++;
    esta = FALSE;}


 }while (i < TAM);


printf("Hay %d concordancias con la contrasena, de las cuales %d estan en el lugar correcto\n", existe, lugar);

  for ( int i = 0; i < TAM; i++){
    if (guardar[i] != 5)
        printf("El color del lugar %d esta en la posicion correcta\n", guardar[i]+1);

  }

if (lugar == TAM){
    printf("FELICIDADES DESCUBRISTE LA CONTRASENA");
    break;
}



intentos--;

}


if (lugar != TAM)
    printf("LO SENTIMOS NO HAS LOGRADO DESCUBRIR LA CONTRASENA");


}
