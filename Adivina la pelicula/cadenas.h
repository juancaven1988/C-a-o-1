#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <stdio.h>
#include "boolean.h"

const int TAM = 80;

typedef char cadenas[TAM];



void scan (cadenas &str1);
//LEE UNA CADENA INGRESADA POR TECLADO//

void print (cadenas str);
//IMPRIME UNA CADENA POR PANTALLA//

int strlar (cadenas str);
//DEVUELVE EL LARGO DE UNA CADENA//


boolean strmen (cadenas str1, cadenas str2);
//DEVUELVE TRUE CUANDO LA CADENA 1 ES MAS CORTA QUE LA CADENA 2 //

boolean streq (cadenas str1, cadenas str2);
// DEVUELVE TRUE CUANDO LAS CADENAS SON IGUALES //

void strcop (cadenas &str1, cadenas str2);
// COPIA LA CADENA 2 EN LA CADENA 1 //


void strcon (cadenas &str1, cadenas str2);
//COPIA LA CADENA 2 AL FINAL DE LA CADENA 1 //


void strswp (cadenas &str1, cadenas &str2);
//INTERCAMBIA LA CADENA 1 Y LA 2 //

void tocap (cadenas &str1);
//COMBIERTE UNA CADENA EN MAYUSCULAS//


#include "cadenas.h"
#endif // CADENAS_H_INCLUDED
