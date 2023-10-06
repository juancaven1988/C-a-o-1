#include <stdio.h>

const int SIZE = 50, MAX = 80;

void mover(int &pos_x, int &pos_y, int floor[SIZE][SIZE], int pluma, int dir, int espacios){



int i = 1;

switch(dir){

case 1:

    while (i <= espacios && pos_x < SIZE){
                pos_x = pos_x + 1;
                 if (pluma == 2)
                    floor[pos_x][pos_y] = 1;
                i++;}
                break;

case 2:

    while (i <= espacios && pos_x < SIZE){
                pos_y = pos_y + 1;
                 if (pluma == 2)
                    floor[pos_x][pos_y] = 1;
                i++;}
                break;


case 3:

    while (i <= espacios && pos_x < SIZE){
                pos_x = pos_x - 1;
                 if (pluma == 2)
                    floor[pos_x][pos_y] = 1;
                i++;}
                break;

case 4:

    while (i <= espacios && pos_x < SIZE){
                pos_y = pos_y - 1;
                 if (pluma == 2)
                    floor[pos_x][pos_y] = 1;
                i++;}
                break;
}

}

void Imprimir (int floor[SIZE][SIZE]){

for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
        if ( floor [i][j] == 0)
            printf (" ");
        else
            printf ("%c",219);
    }
    printf("\n");

}



}



int main()
{
  int floor[SIZE][SIZE]= {{0},{0}};
  int comandos[MAX] = {0};

  /* COMANDOS

  1 - PLUMA ARRIBA
  2 - PLUMA ABAJO
  3 - GIRO A LA DERECHA
  4 - GIRO A LA IZQUIERDA
  5 - MOVER HACIA ADELANTE X POSICIONES
  6 - IMPRIMIR ARREGLO
  9 - FIN DE DATOS */


  int pluma = 1, direccion = 1, pos_x = 24, pos_y = 24, x = 0;


  int i = 0;

  printf ("Ingrese la linea de comandos\n");
  do{
    scanf ("%d", &comandos[i]);
    i++;

  }  while (comandos[i-1] != 9 && i < MAX);

  i = 0;


  do{

    switch (comandos[i]){

    case 1: pluma = 1;
            break;
    case 2 : pluma = 2;
             break;
    case 3 : if (direccion < 4)
                direccion ++;
             else
                direccion = 1;
             break;
    case 4: if (direccion > 1)
                direccion --;
             else
                direccion = 4;
             break;
    case 5: mover(pos_x, pos_y, floor, pluma , direccion, comandos[i+1]);
            i++;
            break;
    case 6: Imprimir (floor);
            break;

    }
i++;

  }while(comandos[i-1] != 9 && i < MAX);


}
