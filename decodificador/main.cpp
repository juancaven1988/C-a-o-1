#include <stdio.h>


int main()
{
int codigo, x, x_1, x_2, x_3, x_4;

printf("Ingrese el codigo: ");
scanf("%d", &codigo);

x_1 = (codigo % 10+ 3) %10;
x_2 = ((codigo/10)%10 + 3) %10;
x_3 = ((codigo/100)%10 + 3) %10;
x_4 = ((codigo/1000)%10 + 3) %10;


x = x_2*1000 + x_4*10 + x_1*100 + x_3;

printf("el mensaje es: %d", x);


    return 0;
}
