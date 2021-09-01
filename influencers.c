#include "animos.h"
#include <stdio.h>
#include <stdbool.h>

static const char MANIANA = 'M';
static const char TARDE = 'T';
static const char NOCHE = 'N';
static const char IZQUIERDA = 'I';
static const char DERECHA ='D';
static const char ENSALADA = 'E';
static const char HAMBURGUESA = 'H';
static const char PIZZA = 'P';
static const char GUISO = 'G';
static const char ANIMO_MALO = 'M';
static const char ANIMO_REGULAR = 'R';
static const char ANIMO_BUENO = 'B';
static const int DIA_MIN = 1;
static const int DIA_MAX = 30;
static const int DIA_CAM_VIENTO_MAX = 11;
static const int DIA_CAM_VIENTO_MED = 21;
static const int SUENIO_MIN = 0;
static const int SUENIO_MAX = 12;
static const int HORA_CAM_SUENIO_MIN = 5;
static const int HORA_CAM_SUENIO_MED = 8;
static const int VIENTO_MAX = 75;
static const int VIENTO_MED = 50;
static const int VIENTO_MIN = 25;
static const int HUMADAD_MAX = 75;
static const int HUMEDAD_MED = 50;
static const int HUMEDAD_MIN = 25;
static const int PUNTOS_PIE_DER = 10;
static const int PUNTOS_ENSALADA = 20;
static const int PUNTOS_HAMBURGUESA = 15;
static const int PUNTOS_PIZZA = 10;
static const int PUNTOS_GUISO = 5;
static const int PUNTOS_SUENIO_MED = 10;
static const int PUNTOS_SUENIO_MAX = 20;
static const int CONTADOR_INICIAL = 0;
static const int PUNTOS_MIN_ANIMO = 5;
static const int PUNTOS_CAM_ANIMO_MALO = 21;
static const int PUNTOS_CAM_ANIMO_REG = 35;




/*void animos (int *viento, int *humedad, char *animo_legolas, char *animo_gimli){
	if (viento == VIENTO_MIN){
		printf("Poco viento, incapaz de volarle el peluquin a alguien, ");
	} else if (viento == VIENTO_MED){
		printf("Viento moderado, abrigate bro, que hace frio, ");
	} else printf("Mucho viento, mete la ropa del tender que se va a volar, ");

	if (humedad == HUMEDAD_MIN){
		printf("humedad baja, ");
	} else if (humedad == HUMEDAD_MED){
		printf("humedad media, ");
	} else printf("humedad alta, ");

	if (animo_legolas == ANIMO_MALO){
		printf("Legolas habra pisado una makumba porque no es un buen dia, ");
	} else if (animo_legolas == ANIMO_REGULAR){
		printf("Legolas no tiene un buen dia pero safa, ");
	} else printf("los dioses del olimpo se sonrien a Legolas porque tiene un buen dia, ");

	if (animo_gimli == ANIMO_MALO){
		printf("Gimli habra pisado una makumba porque no es un buen dia. \n");
	} else if (animo_gimli == ANIMO_REGULAR){
		printf("Gimli no tiene un buen dia pero safa. \n");
	} else printf("los dioses del olimpo se sonrien a Gimli porque tiene un buen dia. \n");*/
int main (){
	
	int viento;
	int humedad;
	char animo_legolas;
	char animo_gimli;

	animos (&viento, &humedad, &animo_legolas, &animo_gimli);
	printf("%i %i %c %c \n", viento, humedad, animo_legolas, animo_gimli);
return 0;
}