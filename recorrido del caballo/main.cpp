#include <stdio.h>
#include<stdlib.h>

const int TAM = 8;

typedef int Tableros [TAM][TAM];
typedef int Movimientos[TAM];

const Movimientos horizontal = {2,1,-1,-2,-2,-1,1,2}, vertical = {-1,-2,-2,-1,1,2,2,1};

void mostrar (const Tableros tablero){

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
        if (tablero[i][j] == 0)
            printf("[ ]");
        else
            if (tablero[i][j] == 1)
               printf("[x]");
             else
                printf("%d ", tablero[i][j]);
    }
      printf ("\n");
  }




}

void analizar (const Tableros recorrido, Tableros opc){


    int i, j, n;


    for ( i = 0; i < TAM; i++){
        for (j = 0; j  < TAM; j++)
            opc[i][j] = 0;}


    for ( i = 0; i < TAM; i++){
        for (j = 0; j  < TAM; j++){
          for (n = 0; n < TAM; n++){

            if (i + vertical[n] >= 0 && i + vertical[n]  < TAM )
              if (j + horizontal[n] >= 0 && j + horizontal[n]  < TAM)
                if (recorrido[i+vertical[n]][j+horizontal[n]] == 0)
                   opc[i][j] = opc[i][j] + 1;
                   if (recorrido[i][j] == 1)
                    opc[i][j] = 0;

            }
        }
    }

}

void mover (const Tableros opciones, Tableros recorrido,int &fila,int &columna){

int menor = 8, menor_f,menor_c;


for (int n = 0; n < TAM; n++){
    if (fila + vertical[n] >= 0 && fila + vertical[n] < TAM){
        if (columna + horizontal[n] >= 0 && columna + horizontal[n] < TAM){
           if (recorrido[fila+vertical[n]][columna+horizontal[n]] == 0){
                if(opciones[fila+vertical[n]][columna+horizontal[n]] < menor){
                    menor = opciones[fila+vertical[n]][columna+horizontal[n]];
                    menor_f = fila+vertical[n];
                    menor_c = columna+horizontal[n];
                }
            }
        }
    }



}

fila = menor_f;
columna = menor_c;

recorrido[fila][columna] = 1;

}

bool posible (int fila, int columna, const Tableros opciones){

bool existe = false;

int n = 0;

do{
      if (opciones[fila+vertical[n]][columna+horizontal[n]] != 0)
            existe = true;
        else
        n++;


}while (!existe && n < TAM);


return existe;}

int main()
{
    Tableros recorrido = {{0},{0}};
    Tableros opciones =  {{0},{0}};


    int fila_actual = 0 ,columna_actual = 0;

    recorrido [fila_actual][columna_actual] = 1;

    mostrar(recorrido);


    for(int m = 1; m < 64; m++){

    analizar(recorrido, opciones);

     if (posible(fila_actual,columna_actual,opciones))
         mover(opciones,recorrido,fila_actual,columna_actual);

    printf("\n");

    mostrar(recorrido);


    printf("Fila actual: %d\nColumna actual: %d\nMovimiento %d\n\n", fila_actual, columna_actual, m);}









}






