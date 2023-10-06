#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define ARRIBA 72
#define ABAJO 80

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

for ( int i = 4; i < 28; i++){
    gotoxy(10, i); printf("%c", 219);
    gotoxy(110, i); printf("%c", 219);
}

for ( int i = 10; i < 111; i++){
    gotoxy(i, 3); printf("%c", 220);
    gotoxy(i, 28); printf("%c", 223);
}



}

class PELOTA {

int x, y, direccion, altura;


public:
    PELOTA (int _x, int _y, int _direccion, int _altura ): y(_y), x(_x), direccion (_direccion), altura (_altura){}
    void mover();
    void dibujar();
    void borrar();
    int X (){return x;}
    int Y (){return y;}
    void reinicio ();
    int cambiar_altu ();
    int cambiar_direccion();


};
void PELOTA::dibujar(){
gotoxy(x,y); printf("%c", 169);

}
void PELOTA::borrar(){
gotoxy(x,y);printf(" ");
}
void PELOTA::mover(){

gotoxy(x,y); borrar();
x = x + direccion;
y = y + altura;
dibujar();

}

int PELOTA::cambiar_direccion(){

direccion = direccion* -1;


return direccion;}

int PELOTA::cambiar_altu(){

altura = altura * -1;


return altura;}

void PELOTA::reinicio(){
x = 60;
y = rand()%22 +5;
}

class PLAYER1 {
 int x, y, puntaje;

 public:
     PLAYER1 (int _x,int _y, int _puntaje): x (_x), y (_y), puntaje (_puntaje){}
     void dibujar();
     void mover ();
     void anotacion(){puntaje++;}
     int Marcador (){return puntaje;}
     int X(){return x;}
     int Y(){return y;}

};

void PLAYER1::dibujar(){

gotoxy(x,y);
for (int i = 0; i < 5; i++){
gotoxy(x, y+i);
printf("%c",219);}

}



void PLAYER1::mover(){

if (kbhit()){
    gotoxy(x,y);printf(" ");
    gotoxy(x,y+4);printf(" ");
    char tecla;
    tecla = getch();
    if (tecla == 'w' && y > 5)y--;
    if (tecla == 's' && y < 22)y++;
    dibujar();}


}


class PLAYER2 {
 int x, y, puntaje;

 public:
     PLAYER2 (int _x,int _y, int _puntaje): x (_x), y (_y), puntaje (_puntaje){}
     void dibujar();
     void mover ();
     void anotacion(){puntaje++;}
     int Marcador (){return puntaje;}
     int X(){return x;}
     int Y(){return y;}

};

void PLAYER2::dibujar(){

gotoxy(x,y);
for (int i = 0; i < 5; i++){
gotoxy(x, y+i);
printf("%c",219);}

}



void PLAYER2::mover(){

if (kbhit()){
    gotoxy(x,y);printf(" ");
    gotoxy(x,y+4);printf(" ");
    char tecla;
    tecla = getch();
    if (tecla == ARRIBA && y > 5)y--;
    if (tecla == ABAJO && y < 22)y++;
    dibujar();}


}


int main()
{
ocultar_cursor();
char inicio;

srand(time(NULL));

int dir_x, dir_y;

dir_x = rand() % 2;
dir_y = rand() % 2;

if (dir_x == 0)
    dir_x = -2;
else
    dir_x = 2;
if (dir_y == 0)
     dir_y = -1;


PELOTA pelota1(50, 10, dir_x, dir_y);
dibujar_cancha();
PLAYER1 paleta1(13,12,0);
PLAYER2 paleta2 (107,12,0);

bool game_over = false, anotacion = false;
int mover_der = 1, mover_izq = 1, velocidad = 140, comienzo_mov;
paleta1.dibujar();
paleta2.dibujar();
gotoxy(45,15); printf("Presione ESPACIO para comenzar" );


gotoxy(10,1); printf("Arriba: W");
gotoxy(10,2); printf("Abajo: S");
gotoxy(91,1);printf("Arriba: Flecha arriba");
gotoxy(92,2);printf("Abajo: Flecha abajo");

while (!game_over){

        gotoxy(56,1); printf("MARCADOR", paleta1.Marcador(),'|','|', paleta2.Marcador());
        gotoxy(56,2); printf("%d  %c%c  %d", paleta1.Marcador(),'|','|', paleta2.Marcador());

if (kbhit()){
        char inicio;
        inicio = getch();
        if (inicio == ' '){
                anotacion = false;
                gotoxy(45,15); printf("                               " );

   while (!anotacion){

    pelota1.dibujar();

                                         /* JUEGO */

               pelota1.mover();
               Sleep(velocidad);
               paleta1.mover();
               paleta2.mover();


          if (pelota1.X() >= 108 || pelota1.X() <= 12){
             anotacion = true;
             pelota1.cambiar_direccion();}

         if (pelota1.X() == paleta2.X()-1 && (pelota1.Y() >= paleta2.Y() && pelota1.Y() < paleta2.Y()+6)){
            pelota1.cambiar_direccion();
            velocidad -= 2;}
         if (pelota1.X() == paleta1.X()+1 && (pelota1.Y() >= paleta1.Y() && pelota1.Y() < paleta1.Y()+6)){
            pelota1.cambiar_direccion();
            velocidad -= 2;}
         if (pelota1.Y() >= 27 || pelota1.Y() <= 5)
                pelota1.cambiar_altu();


   }

                    /* ANOTACION JUGADOR 2*/

             if (pelota1.X() <= 12){
                paleta2.anotacion();
                pelota1.borrar();
                pelota1.reinicio();
                velocidad = 140;
                gotoxy(45,15); printf("Presione ESPACIO para continuar" );
             }

                   /*ANOTACION JUGADOR 1*/
             if (pelota1.X() >= 108){
                paleta1.anotacion();
                pelota1.borrar();
                pelota1.reinicio();
                velocidad = 140;
                gotoxy(45,15); printf("Presione ESPACIO para continuar" );
             }


             if (paleta1.Marcador() == 10 || paleta2.Marcador() == 10)
                game_over = true;








}



}}
gotoxy(56,1); printf("MARCADOR", paleta1.Marcador(),'|','|', paleta2.Marcador());
gotoxy(45,15); printf("                                 " );
        gotoxy(56,2); printf("%d  %c%c  %d", paleta1.Marcador(),'|','|', paleta2.Marcador());
        gotoxy(55,15); printf("GAME OVER");
        gotoxy(1,30);

}
