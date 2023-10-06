#include<stdio.h>
#include "cadenas.h"


void scan (cadenas &str1){

fflush(stdin);
int i = 0;
scanf("%c", &str1[i]);
while (i < TAM - 1 && str1[i] != '\n'){
    i++;
	scanf("%c", &str1[i]);

}

str1[i] = '\0';

}

void print (cadenas str){

int i = 0;

while (str[i] != '\0' && i < TAM){
	printf("%c", str[i]);
	i++;}


}

int strlar (cadenas str){

int i = 0;

while (str[i] != '\0' && i < TAM){
	i++;

}

return i;}


boolean strmen (cadenas str1, cadenas str2){

boolean menor = FALSE;

int i = 0;

while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'){
	i++;

}

if (str1[i] < str2[i])
	menor = TRUE;

return menor;}

boolean streq (cadenas str1, cadenas str2){

boolean iguales = TRUE;

int i = 0;



while (iguales && str1[i] != '\0' && str2[i] != '\0'){

	if (str1[i] != str2 [i])
		iguales = FALSE;
	else
	i++;

}

if (str1[i] != '\0' || str2[i] != '\0')
	iguales = FALSE;

return iguales;}

void strcop (cadenas &str1, cadenas str2){

int i = 0;

while (str2[i] != '\0' && i < TAM -1){

	str1[i] = str2[i];
	i++;
}

str1[i] = '\0';

}

void strcon (cadenas &str1, cadenas str2){

int i = 0, j = 0;

while (i < TAM && str1[i] != '\0'){
     i++;}

while (i < TAM -1 && str2[j] != '\0'){
	str1[i] = str2[j];
	i++;
	j++;

}

str1[i] = '\0';

}

void strswp (cadenas &str1, cadenas &str2){

cadenas temp;

		strcop(temp, str1);
		strcop(str1, str2);
		strcop(str2, temp);
}

void tocap (cadenas &str1){

int i = 0;

do{

	if(str1[i] >= 'a' && str1 [i] <= 'z')
		str1[i] = str1[i]- 32;
	i++;

}while (i < TAM && str1[i] != '\0');

}
