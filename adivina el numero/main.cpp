#include <stdio.h>;
#include <time.h>;
#include <stdlib.h>;
typedef enum {FALSE, TRUE} boolean;
int main()
{
srand(time(NULL));
int numAleatorio = rand()%101;
///////* Comienzo de solución *///////
int num, intentos = 1;
boolean finJuego = FALSE;
printf("Intente adivinar el número del 1 al 100");
while(finJuego == FALSE && intentos <= 5)
{
    printf("\nIntento %d: ", intentos);
    scanf("%d",&num);
        if(num == numAleatorio)
            {
            finJuego = TRUE;
            printf("\nFelicidades, ha adivinado!");
            }
        else
            {
            if(num > numAleatorio)
            printf("Ha ingresado un número mayor");
            else
            printf("Ha ingresado un número menor");
            }
intentos++;
}
if(finJuego == FALSE)
printf("\nNo le quedan más intentos. El número a adivinar era: %d", numAleatorio);
return 0;
}
