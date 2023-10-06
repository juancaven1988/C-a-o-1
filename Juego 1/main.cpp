#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include<time.h>
using namespace std;

#define ARRIBA 72                     /*valor ASCII de ARRIBA */
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
const int S = 3, V = 3;



void gotoxy(int a, int b)
{
    HANDLE hcon;  /*HANDLE crea una variable que indica lo que vamos a manipular */
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);    /*le indico a la variable que quiero manipular la salida */

    COORD hconcord;    /*variable de cordenda */

    hconcord.X = a;       /*coordenada x va de 0 izq a der */
    hconcord.Y = b;       /*coordenada y va de 0 arriba hacia abajo */

    SetConsoleCursorPosition(hcon, hconcord);    /*coloco el cursor en lo que manipulo y las coordenadas */
    }

void ocultar_cursor(){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO cci;

      cci.dwSize = 50;                    /*setea el tamaño */
      cci.bVisible = FALSE;               /* setea la visibilidad */

      SetConsoleCursorInfo(hcon, &cci);           /*setconsolecursorinfo pide un valor HANDLE por valor y un valor CONSOLE CURSOR INFO por referencia */
    }


class NAVE{

    int x, y;
    int salud_act;
    int salud;
    int vidas;

public:
    NAVE (int _x, int _y, int _salud, int _vidas): x(_x), y(_y), salud(_salud), vidas (_vidas){}
    void pintar();
    void borrar ();
    void mover ();
    void pintar_salud();
    void morir();
    int X(){return x;}
    int Y(){return y;}
    void Danio(){salud--;}
    int Vidas(){return vidas;}

}    ;


void NAVE::morir(){



   if (salud == 0){
       borrar();
   gotoxy(x,y);
printf(" %c%c",220,191);
gotoxy(x,y+1);
printf("  %c%c",223,223);
   Sleep(250);
   borrar();
   gotoxy(x,y); printf("  * * ");
   gotoxy(x,y+1); printf("  * * * ");
   Sleep(250);
   borrar();
   vidas --;
   salud = S ;
   pintar_salud();
   pintar();}


}

void NAVE::pintar_salud(){

gotoxy(50,2);printf("Vidas: %d", vidas);
gotoxy(107,2);
printf("Salud:");
gotoxy(113,2);
printf("     ");
for (int i= 0; i < salud; i++)
{
    gotoxy(113+i,2);printf("%c", 254);
}

}
void NAVE::pintar(){
gotoxy(x,y);
printf(" %c%c%c%c",220,220,194,191);
gotoxy(x,y+1);
printf("  %c%c%c%c",223,223,223,223);

}

void NAVE ::borrar(){
gotoxy(x,y); printf("       ");
gotoxy(x,y+1); printf("       ");
}

void NAVE ::mover(){

 if(kbhit()){                            /*la funcion kbhit de conio.h permite al programa saber si se preciono una tecla */
            char tecla = getch();               /*getch toma el caracter que se presiona */
            borrar();
            if(tecla == DERECHA && x < 110) x++;
            if(tecla == IZQUIERDA && x > 3) x--;
            if(tecla == ARRIBA && y > 4) y--;
            if(tecla == ABAJO && y < 26) y++;

            pintar();
            pintar_salud();}
}

void pintar_limites(){
 for ( int i = 2; i < 119; i++){
    gotoxy(i, 3);
    printf("%c",205);
    gotoxy(i,28);
    printf("%c",205);}

  for (int i = 4; i < 29; i++){
    gotoxy(2, i);
    printf("%c",186);
    gotoxy(118, i);
    printf("%c",186);
  }

  gotoxy(2,3);
  printf("%c", 201);
  gotoxy(2,28);
  printf("%c",200);
  gotoxy(118,3);
  printf("%c", 187);
  gotoxy(118,28);
  printf("%c", 188);

}

class ASTEROIDE{
int x, y;

public:
    ASTEROIDE (int _x, int _y): x(_x), y(_y){};
    void pintar();
    void mover ();
    void colicion(class NAVE &nave);
    void borrar();
    int X(){return x;};
    int Y(){return y;};

};

void ASTEROIDE::borrar(){
printf(" ");
}

void ASTEROIDE::colicion(class NAVE &nave){

if (x <= nave.X()+5 && x >= nave.X() && y <= nave.Y()+1 && y >= nave.Y() ){
    nave.Danio();
    pintar();
    nave.borrar();
    nave.pintar();
    nave.pintar_salud();
    y = rand()%22 + 4;
    x = 117;

}


}
void ASTEROIDE::pintar(){
 gotoxy(x,y); printf("%c", 184);

}

void ASTEROIDE::mover(){
gotoxy(x,y); printf(" ");
x--;
if (x < 4 ){
    y = rand()%22 + 4;
    x = 117;
}
pintar();

}

class BALA{

int x, y;

public:
    BALA (int _x, int _y): x(_x), y(_y){}
    void mover();
    int X(){return x;};
    int Y(){return y;};
    bool limite ();


};

bool BALA::limite(){
if (x == 117)
return true;
return false ;

}



void BALA::mover(){
gotoxy(x,y); printf(" ");
if (x < 117) x++;
gotoxy(x,y); printf("-");
}





    int main(){

    ocultar_cursor();
    pintar_limites();
    bool game_over = false;
    NAVE nave(3,10,S,V);
    nave.pintar();
    nave.pintar_salud();
    int puntaje = 0;


   list<BALA*> B;
   list<BALA*>::iterator it;


   list<ASTEROIDE*> A;
   list<ASTEROIDE*>:: iterator ast;

    for (int i = 0; i < 7; i++){
      A.push_back (new ASTEROIDE(rand()%4+114, rand()%22 + 4));
      }

    while(!game_over){

      gotoxy(1,2); printf("Puntaje: %d", puntaje);

      if(kbhit()){
        char tecla = getch();
        if (tecla == ' '){
            B.push_back(new BALA(nave.X()+6, nave.Y()+1)) ;
                        }
      }

      for (it = B.begin(); it != B.end(); it++){
        (*it)->mover();
              if ((*it)->limite()){
                gotoxy((*it)->X(), (*it)->Y());printf(" ");
                delete (*it);
                it = B.erase (it);

              }

      }


      for (ast = A.begin(); ast != A.end(); ast++){
        (*ast)->mover();
        (*ast)->colicion(nave);
      }


      for (ast = A.begin(); ast != A.end(); ast++){

        for (it = B.begin(); it != B.end(); it++)

            if (((*it)->X() == (*ast)->X()-1 || (*it)->X() == (*ast)->X())&& (*it)->Y() == (*ast)->Y()){
                gotoxy((*ast)->X()-1,(*ast)->Y());
                printf("  ");

                delete (*it);
                it = B.erase (it);

                delete (*ast);
                ast = A.erase (ast);

                A.push_back (new ASTEROIDE(116, rand()%22 + 4));
                puntaje+=10;

                }



      }

      nave.mover();
      nave.morir();






        Sleep(30);

       if(nave.Vidas() == 0)
        game_over = true;

    }
    nave.borrar();
    for (ast = A.begin(); ast !=A.end(); ast++){
        gotoxy((*ast)->X(),(*ast)->Y());printf (" ");
    }
    gotoxy(54, 12);
    printf("GAME OVER\n");
    gotoxy(54, 13);
    printf("PUNTAJE : %d",puntaje);

    gotoxy(0,30);


    }
