#include <stdio.h>

const int TAM = 80;

typedef enum {FALSE, TRUE} boolean;
typedef char cadenas[TAM];

int main()
{

    cadenas contrasena;
    boolean a = FALSE, b = FALSE, c = FALSE, d = FALSE;
    int i = 0;
    char car;


    printf("Ingrese una contrasena: \n");
    printf("La contrasena debe contener al menos una mayuscula,\n");
    printf("al menos un digito, un caracter especial y como minimo 8 caracteres\n");

while (a == FALSE || b == FALSE || c == FALSE || d == FALSE){
    scanf("%c", &car);


    while (i < TAM-1 && car != '\n')
    {
        contrasena[i] = car;
        i++;
        scanf("%c", &car);

    }

    contrasena[i] = '\0';


    /* condicion a) debe contener una mayuscula */
    /* condicion b) debe contener un digito */
    /*condicion c) debe contener un caracter especial */
    /* condicion d) debe tener al menos 8 caracteres */

    if (i > 8)
        d = TRUE;

    i = 0;

    while (contrasena[i] != '\0' && (a == FALSE || b == FALSE || c == FALSE)){

        if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
            a = TRUE;
        if (contrasena[i] >= '0' && contrasena[i] <= '9')
                  b = TRUE;
        if ( !(contrasena[i] >= 'A' && contrasena[i] <= 'Z') && !(contrasena[i] >= 'a' && contrasena[i] <= 'z')&& !(contrasena[i] >= '0' && contrasena[i] <= '9') && contrasena[i] !='\0' )
                  c = TRUE;

        i++;

    }


    if( a == FALSE || b == FALSE || c == FALSE || d == FALSE)
    {
        if (a == FALSE)
            printf("La contrasena debe contener una MAYUSCULA\n");
        if (b == FALSE)
            printf("La contrasena debe contener un DIGITO\n");
        if (c == FALSE)
            printf("La contrasena debe contener un Caracter especial\n");
        if (d == FALSE)
            printf("La contraseña debe ser de al menos 8 caracteres\n");

        fflush(stdin);
        i= 0;
        printf("Ingrese una nueva contraseña");

    }
    else
        printf("CONTRASENA VALIDADA CORRECTAMENTE");

}}



