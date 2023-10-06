#include <stdio.h>

const int N = 80;

typedef enum {FALSE, TRUE}boolean;
typedef char str[N];

int main()
{
    boolean capicua = TRUE;
    str cadena1;
    char c;
    int i = 0, n;

    printf("Ingrese una cadena:\n");
    scanf("%c", &c);

    while (i < N-1 && c !='\n'){
        cadena1[i] = c;
        i++;
        scanf("%c", &c);

    }
    cadena1[i] = '\0';

    n = i-1;

    i = 0;

    while (i < n && capicua == TRUE){

        if (cadena1[i] != cadena1[n])
            capicua = FALSE;
        else {
            i++;
            n--;
        }
    }

    if (capicua == FALSE)
        printf(" La cadena no es capicua");
    else
        printf("La cadena es capicua");

}
