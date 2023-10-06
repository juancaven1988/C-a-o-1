#include <stdio.h>


main()
{

int x, x_1, x_2, x_3, x_4, codigo;


printf("Ingrese un numero de 4 digitos: ");
scanf("%d", &x);
/*obtener digitos y codificarlos*/
x_1 = ((x % 10)+7) % 10;
x_2 = ((x/10) % 10 +7) % 10;
x_3 = ((x/100) % 10 +7) % 10;
x_4 = ((x/1000) % 10 +7) % 10;

/*modificar orden del codigo*/

codigo = x_4*10 + x_3 + x_2*1000 + x_1*100;

printf("El codigo cifrado es %d\n****************\n", codigo);


    return 0;
}
