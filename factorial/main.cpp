#include <stdio.h>



int fact(unsigned int);

int main(){

unsigned int z;
double e = 1;

for (z =1; z<= 30; z++){

    e = e + (float)1/fact(z);
}

printf("El valor aproximado de la constante 'e' es: %.4f", e);

}



int fact(unsigned int n)
{
 unsigned int factorial = 1;

 if(n > 0){
 for (n; n != 0; n--){

    factorial = factorial * n;

 }

  }

    return factorial;
}


