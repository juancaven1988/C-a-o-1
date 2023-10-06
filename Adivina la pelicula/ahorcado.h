#ifndef AHORCADO_H_INCLUDED
#define AHORCADO_H_INCLUDED

#include "cadenas.h"

void crear_espacios (cadenas pelicula, cadenas &adivinanza);
//crea una cadena de guiones y espacios igual a la pelicula//

void generar_intentos (int &intentos);
//pregunta cuantos intentos desea dar//

void crear_errores (cadenas &errores, int intentos);
//crea una cadena con espacios con la cantidad de intentos//

boolean opcionadivinar (cadenas pelicula, cadenas adivinar);
//DEVUELVE TRUE SI ADIVINA LA PELICULA//

boolean chekadv (cadenas errores);
//COMPRUEBA SI QUEDAN ESPACIOS SIN ADIVINAR//

boolean colocarletra (cadenas pelicula,  cadenas &adivinanza, char c);
//COMPRUEBA QUE LA LETRA DE LA OPCION ESTE EN LA CADENA PELICULA //

#endif // AHORCADO_H_INCLUDED
