#include <stdio.h>



void mover(int n, int  uno,int aux, int tres)
{
if (n > 1){
   mover(n-1, uno, tres, aux);
   printf("%d a %d\n" ,uno,tres);
   mover(n-1, aux, uno,tres);
}
else
    printf("%d a %d\n", uno, tres);

}






int main(){

int n=5;


mover(n,1,2,3);





}















