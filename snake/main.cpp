#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define LIMIT_DER 2
#define LIMIT_IZQ 53
#define LIMIT_SUP 1
#define LIMIT_INF 28

void gotoxy (int x, int y){

HANDLE hcons;

hcons = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwcur;

dwcur.X = x;
dwcur.Y = y;

SetConsoleCursorPosition(hcons, dwcur);
}
void ocultar_cursor (){
HANDLE hcons;
hcons = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_CURSOR_INFO dwnot;

dwnot.bVisible = false;
dwnot.dwSize = 5;

SetConsoleCursorInfo(hcons, &dwnot);

}

void dibujar_cancha(){

for ( int i = LIMIT_SUP; i <= LIMIT_INF; i++){
    gotoxy(LIMIT_DER, i); printf("%c", 219);
    gotoxy(LIMIT_IZQ, i); printf("%c", 219);
}

for ( int i = LIMIT_DER; i <= LIMIT_IZQ; i++){
    gotoxy(i, LIMIT_SUP); printf("%c", 220);
    gotoxy(i, LIMIT_INF); printf("%c", 223);
}

}


class SNAKE {

int x, y, vel_x = 1,  vel_y = 0, largo;
int cuerpox[120], cuerpoy[120];



public:
    SNAKE (int _x, int _y, int _largo): x (_x), y (_y), largo (_largo) {}

   bool colicion = false;
   void dibujar();
   void borrar();
   void mover();
   void cambiar_dir();
   int X() {return x;}
   int Y() {return y;}
   void armar_cuerpo();
   void dibujar_cuerpo();
   void borrar_cuerpo();
   void mover_cuerpo();
   void aumentar();
   bool col(){return colicion;}

};




void SNAKE::aumentar(){

largo = largo + 1;

}

void SNAKE::armar_cuerpo(){

cuerpox[0] = x - 1;
cuerpoy[0] = y - 1;

for (int i = 1; i < largo; i++){
cuerpox[i] = cuerpox[i-1]-1;
cuerpoy[i] = cuerpoy[i-1]-1;}

}

void SNAKE::dibujar_cuerpo(){

for(int i = 0; i < largo; i++){
    gotoxy(cuerpox[i],cuerpoy[i]);
    printf("%c", 219);

}


}

void SNAKE::borrar_cuerpo(){

for(int i = 0; i < largo; i++){
    gotoxy(cuerpox[i],cuerpoy[i]);
    printf(" ");

}


}

void SNAKE::mover_cuerpo(){


for (int i = largo-1; i > 0; i--){
    cuerpox[i] = cuerpox[i-1];
    cuerpoy[i] = cuerpoy[i-1];
    if ( cuerpox[i] == x && cuerpoy[i] == y)
        colicion = true;

}
cuerpox[0] = x;
cuerpoy[0] = y;

}

void SNAKE::dibujar(){


gotoxy(x,y);
printf("%c", 219);

}

void SNAKE::borrar(){


gotoxy(x,y);
printf(" ");


}

void SNAKE::cambiar_dir(){

char tecla;

    if (kbhit()){
            colicion = false;
        tecla = getch();

        if ( tecla == ARRIBA && vel_y != 1){
              vel_y = -1; vel_x = 0;}

        if ( tecla == ABAJO && vel_y != -1){
              vel_y = 1; vel_x = 0;}

        if ( tecla == DERECHA && vel_x != -1){
              vel_x = 1; vel_y = 0;}

        if ( tecla == IZQUIERDA && vel_x != 1){
              vel_x = -1; vel_y = 0;}
                     }


}

void SNAKE::mover(){

    borrar_cuerpo();
    gotoxy(x,y);
    borrar();
    mover_cuerpo();
    x = x + vel_x;
    y = y + vel_y;

    if(x <= LIMIT_DER  || x >= LIMIT_IZQ  )
                colicion = true;
                   else {
                      if (y >= LIMIT_INF  || y <= LIMIT_SUP )
                        colicion = true;

                        }


    gotoxy(x, y);
    dibujar();
    dibujar_cuerpo();


}


class COMIDA {

int x, y;

public:

    COMIDA (int _x, int _y): x(_x), y(_y){};

    void reiniciar();
    void dibujar();
    void borrar();
    int X(){return x;}
    int Y(){return y;}


};

void COMIDA::dibujar(){

gotoxy(x,y);
printf("@");


}

void COMIDA::borrar(){

gotoxy(x,y);
printf(" ");


}

void COMIDA::reiniciar(){

gotoxy(x,y);
borrar();
x = rand()%43 + 5;
y = rand()%22 + 3;
gotoxy(x,y);
dibujar();


}



int main (){

srand(time(NULL));
bool gameover = false;
int puntuacion = 0, velocidad = 140;
char c;
SNAKE jugador(25, 14, 3);
COMIDA food(rand()%43 + 5,rand()%22 + 3 );
ocultar_cursor();
dibujar_cancha();

gotoxy(9,14);
printf("'PRESIONE ESPACIO PARA COMENZAR'");


char inicio;
            inicio = getch();

    if ( inicio == ' '){

    gotoxy( 9,14);
    printf("                                ");




 while (!gameover){






 jugador.dibujar();

 gotoxy(1,1);
 printf("Puntuacion: %d", puntuacion);
 food.dibujar();
 jugador.cambiar_dir();
 jugador.mover();
   if (jugador.X() == food.X() && jugador.Y() == food.Y()){
               jugador.aumentar();
               food.reiniciar();
               puntuacion += 50;}
    if (jugador.col() == true)
        gameover = true;
    switch (puntuacion){
     case 500: velocidad = 120;
     break;
     case 1000: velocidad = 100;
     break;
     case 1500: velocidad = 80;
     break;
     case 2000: velocidad = 60;
     break;
     case 2500: velocidad = 40;
     break;
     case 3000: velocidad = 30;
     break;
     case 3500: velocidad = 20;
     break;
     case 4000: velocidad = 10;
     break;
    }

Sleep(velocidad);

}}
food.borrar();
dibujar_cancha();
gotoxy(15, 14);
printf("Su puntuacion fue: %d\n", puntuacion);
gotoxy(19, 15);
printf("GAME OVER");


gotoxy(1,30);
return 0;}
