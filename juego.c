#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "animos.h"
#include "defendiendo_torres.h"
#include "utiles.h"
const static int FILA_TORRE_1_LVL_1 = 7;
const static int COL_TORRE_1_LVL_1 = 0;
const static int FILA_ENTRADA_LVL_1 = 0;
const static int COL_ENTRADA_LVL_1 = 14;
const static int FILA_TORRE_2_LVL_2 = 7;
const static int COL_TORRE_2_LVL_2 = 14;
const static int FILA_ENTRADA_LVL_2 = 14;
const static int COL_ENTRADA_LVL_2 = 0;
const static int FILA_TORRE_1_LVL_3 = 19;
const static int COL_TORRE_1_LVL_3 = 4;
const static int FILA_TORRE_2_LVL_3 = 19;
const static int COL_TORRE_2_LVL_3 = 14;
const static int FILA_ENTRADA_1_LVL_3 = 0;
const static int COL_ENTRADA_1_LVL_3 = 0;
const static int FILA_ENTRADA_2_LVL_3 = 0;
const static int COL_ENTRADA_2_LVL_3 = 19;
const static int FILA_ENTRADA_1_LVL_4 = 19;
const static int COL_ENTRADA_1_LVL_4 = 0;
const static int FILA_ENTRADA_2_LVL_4 = 19;
const static int COL_ENTRADA_2_LVL_4 = 19;
const static int FILA_TORRE_1_LVL_4 = 0;
const static int COL_TORRE_1_LVL_4 = 4;
const static int FILA_TORRE_2_LVL_4 = 0;
const static int COL_TORRE_2_LVL_4 = 15; 
const static int MAX_TABLERO_CHICO = 15;
const static int MAX_TABLERO_GRANDE = 20;
const static int PRIMER_NIVEL = 1;
const static int SEGUNDO_NIVEL = 2;
const static int TERCER_NIVEL = 3;
const static int CUARTO_NIVEL = 4;
const static int INICIO_MAPA = 0;
const static int ERROR = -1;
const static int CONTADOR_INICIAL = 0;
const static int INICIO_CAMINO = 0;
const static int CONSE_DEF_EXTRA = 50;
const static int MAX_DEF_PRIMER_LVL = 5;
const static int MAX_DEF_SEGUNDO_LVL = 5;
const static int MAX_DEF_TERCER_LVL = 6;
const static int MAX_DEF_CUARTO_LVL = 8;
const static int INCONCLUSO = 0;
const static int MIN_ORCOS_DEF_EXTRA_1 = 25;
const static int MIN_ORCOS_DEF_EXTRA_2 = 50;
const static int NULO = 0;
const static int MAX_ENEMIGOS_SEGUNDO_LVL = 200;
const static int MAX_ENEMIGOS_TERCER_LVL = 300;
const static int MAX_ENEMIGOS_CUARTO_LVL = 500;
const static int PREG_LVL_BAJOS = 4;
const static int PREG_LVL_3 = 6;
const static int PREG_LVL_4 = 10;
const static int VIENTO_MAX = 75;
const static int VIENTO_MED = 50;
const static int VIENTO_MIN = 25;
const static int HUMEDAD_MAX = 75;
const static int HUMEDAD_MED = 50;
const static int HUMEDAD_MIN = 25;
const static int DERROTA = -1;
const static int VICTORIA = 1;
const static int PRIMERA_OPCION = 1;
const static int SEGUNDA_OPCION = 2;
const static int TERCERA_OPCION = 3;
const static char ANIMO_MALO = 'M';
const static char ANIMO_REGULAR = 'R';
const static char ANIMO_BUENO = 'B';
const static char AFIRMATIVO_MAY = 'Y';
const static char EXIT = 'E';
const static char NEGATIVO_MAY = 'N';
const static char ENANOS = 'G';
const static char ELFOS = 'L';
/*
POST: imprime por pantalla las opciones que tiene el usuario en el menu.
*/
void opciones(int *respuesta){
	printf("1)Comenzar juego.\n");
	printf("2)Responder preguntas.\n");
	printf("3)EXIT.\n");
	scanf(" %i", &(*respuesta));
}
/*
POST: devolvera true si es que la respuesta coincide con el parametro dado, caso contrario,
	devolvera false. 
*/
bool letra_valida(char respuesta){
	return((respuesta == AFIRMATIVO_MAY) || (respuesta == NEGATIVO_MAY));
}
/*
POST: imprime por pantalla las opciones que tiene el usuario en el menu y ejecuta la opcion 
	elegida.
*/
void menu(int *viento, int *humedad, char *animo_legolas, char *animo_gimli, char *respuesta_menu){
	int respuesta;
	int numero_aleatorio;
	char respuesta_2 = AFIRMATIVO_MAY;
	printf("                    DEFENDIENDO TORRES\n");
	opciones(&respuesta);
	if(respuesta == PRIMERA_OPCION){
		printf("ATENCION!!\n");
		printf("se cargaran aleatoriamente los porcentajes de humedad, viento y animos de lideres de los defensores.\n");
		printf("¿Desea continuar?\n");
		printf("Y/N\n");
		scanf(" %c", &respuesta_2);
		while(letra_valida(respuesta_2) == false){
			printf("ERROR!!\n");
			printf("letra no valida.... \n");
			printf("Y / N\n");
			scanf(" %c", &respuesta_2);
		}
		if(respuesta_2 == NEGATIVO_MAY){
			system("clear");
			menu(&(*viento), &(*humedad), &(*animo_legolas), &(*animo_gimli), &(*respuesta_menu));
		}else{
			numero_aleatorio = rand() % 3 + 1;
			if(numero_aleatorio == PRIMERA_OPCION){
				*viento = VIENTO_MIN;
			}else if(numero_aleatorio == SEGUNDA_OPCION){
				*viento = VIENTO_MED;
			} else{
				*viento = VIENTO_MAX;
			}
			numero_aleatorio = rand() % 3 + 1;
			if(numero_aleatorio == PRIMERA_OPCION){
				*humedad = HUMEDAD_MIN;
			}else if(numero_aleatorio == SEGUNDA_OPCION){
				*humedad = HUMEDAD_MED;
			} else{
				*humedad = HUMEDAD_MAX;
			}
			numero_aleatorio = rand() % 3 + 1;
			if(numero_aleatorio == PRIMERA_OPCION){
				*animo_legolas = ANIMO_MALO;
			}else if(numero_aleatorio == SEGUNDA_OPCION){
				*animo_legolas = ANIMO_REGULAR;
			} else{
				*animo_legolas = ANIMO_BUENO;
			}
			numero_aleatorio = rand() % 3 + 1;
			if(numero_aleatorio == PRIMERA_OPCION){
				*animo_gimli = ANIMO_MALO;
			}else if(numero_aleatorio == SEGUNDA_OPCION){
				*animo_gimli = ANIMO_REGULAR;
			} else{
				*animo_gimli = ANIMO_BUENO;
			}
			system("clear");

		}
	}else if(respuesta == SEGUNDA_OPCION){
		system("clear");
		animos(&(*viento), &(*humedad), &(*animo_legolas), &(*animo_gimli));
		system("clear");
	} else if(respuesta == TERCERA_OPCION){
		*respuesta_menu = EXIT;

	}
} 
/*
POST: imprime por pantalla las caracteristicas del nivel que se esta por jugar.
*/
void presentar_nivel(int nivel_actual){
	char respuesta;
	
	if(nivel_actual == PRIMER_NIVEL){
		printf("                          NIVEL 1!!!\n");
		printf("los orcos ingresaran por la parte derecha del tablero, y la torre sera\n");
		printf("defendida inicialmente por 5 enanos, los cuales seran posicionados por el\n");
		printf("jugador. Cada 25 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un enano extra, a costa de restarle 50 puntos a la torre 1.\n");
		printf("El objetivo es defender la torre 1 con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else if(nivel_actual == SEGUNDO_NIVEL){
		printf("                          NIVEL 2\n");
		printf("los orcos ingresaran por la parte izquierda del tablero, y la torre sera\n");
		printf("defendida inicialmente por 5 elfos, los cuales seran posicionados por el\n");
		printf("jugador. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo extra, a costa de restarle 50 puntos a la torre 2.\n");
		printf("El objetivo es defender la torre 2 con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else if(nivel_actual == TERCER_NIVEL){
		printf("                          NIVEL 3\n");
		printf("los orcos ingresaran por la parte de arriba del tablero, en dos caminos, y las torres seran\n");
		printf("defendidas inicialmente por 6 defensores, 3 enanos y 3 elfos, los cuales seran posicionados por el\n");
		printf("jugador, donde primero se colocaran los enanos y despues los elfos. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo o un enano extra, a costa de restarle 50 puntos a la torre 1 en caso de ser un enano o 50 puntos a la torre 2 en caso de ser un elfo.\n");
		printf("El objetivo es defender las dos torres con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");
	}else{
		printf("                          NIVEL 4\n");
		printf("los orcos ingresaran por la parte de abajo del tablero, en dos caminos, y las torres seran\n");
		printf("defendidas inicialmente por 8 defensores, 4 enanos y 4 elfos, los cuales seran posicionados por el\n");
		printf("jugador, donde primero se colocaran los enanos y despues los elfos. Cada 50 orcos ingresados en el camino, se tendra la posibilidad\n");
		printf("de agregar un elfo o un enano extra, a costa de restarle 50 puntos a la torre 1 en caso de ser un enano o 50 puntos a la torre 2 en caso de ser un elfo.\n");
		printf("El objetivo es defender las dos torres con exito de la invasion de orcos\n");
		printf("Presione una letra para continuar:\n");
		scanf(" %c", &respuesta);
		system("clear");


	}
}

/*
POST: devolvera true si las coodenadas estan dentro del rango valido, caso contrario,
	devolvera false.
*/
bool coodenadas_validas(int nivel_actual, coordenada_t posicion){
	if(nivel_actual == PRIMER_NIVEL || nivel_actual == SEGUNDO_NIVEL){
		if((posicion.fil >= INICIO_MAPA && posicion.fil < MAX_TABLERO_CHICO) && (posicion.col >= INICIO_MAPA && posicion.col < MAX_TABLERO_CHICO)){
			return true;
		}
	}
	if(nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL){
		if((posicion.fil >= INICIO_MAPA && posicion.fil < MAX_TABLERO_GRANDE) && (posicion.col >= INICIO_MAPA && posicion.col < MAX_TABLERO_GRANDE)){
			return true;
		}
	}
return false;
}
/*
POST: se rellena el vector defensor con las coordenadas de cada defensor.
*/
void agregar_ayudantes(juego_t *juego){
	int resultado;
	int defensor_nuevo;
	coordenada_t posicion;
	defensor_nuevo = juego->nivel.tope_defensores;
	printf("los defensores son %i \n", juego->nivel.tope_defensores);
	printf("ingresar fila para poner el defensor %i \n", defensor_nuevo + 1);
	scanf(" %i", &posicion.fil);
	printf("ingresar columna para poner el defensor %i \n", defensor_nuevo + 1);
	scanf(" %i", &posicion.col);
	resultado = agregar_defensor(&(juego->nivel), posicion, juego->nivel.defensores[defensor_nuevo].tipo);
	system("clear");	
	mostrar_juego(*juego);
	while((resultado == ERROR) || (coodenadas_validas(juego->nivel_actual, posicion) == false)){
		printf("ERROR, fila o columna no valida, por favor:\n");
		printf("ingresar fila para poner el defensor %i \n", defensor_nuevo + 1);
		scanf(" %i", &posicion.fil);
		printf("ingresar columna para poner el defensor %i \n", defensor_nuevo + 1);
		scanf(" %i", &posicion.col);
		resultado = agregar_defensor(&(juego->nivel), posicion, juego->nivel.defensores[juego->nivel.tope_defensores].tipo);
		system("clear");	
		mostrar_juego(*juego);
	}
}
/*
PRE: deben ingresar los orcos por el camino.
POST: devolvera la cantidad de orcos que estan actualmente en el nivel.
*/		
int cantidad_orcos_en_nivel(nivel_t nivel){
	int contador = CONTADOR_INICIAL;
	for (int i = 0; i <  nivel.tope_enemigos;++i){
		if (nivel.enemigos[i].pos_en_camino >= INICIO_CAMINO){
			contador++;
		}
	}
return contador;
}

/*
POST: devuelve true si es que la letra corresponde a uno de los dos tipos de defensores
	validos, caso contrarip, devuelve false.
*/
bool tipo_valido(char tipo, int nivel_actual){
	if((nivel_actual == PRIMER_NIVEL) && (tipo == ENANOS)){
		return true;
	}else if((nivel_actual == SEGUNDO_NIVEL) && (tipo == ELFOS)){
		return true;
	}else if((nivel_actual == TERCER_NIVEL || nivel_actual == CUARTO_NIVEL) && (tipo == ENANOS || tipo == ELFOS)){
		return true;
	}else return false;

}
/*
PRE: deben haber ingresado los orcos al camino.
POST: agrega un defensor nuevo al vector defensor.
*/
void agregar_ayudante_extra(juego_t *juego){
	char respuesta;
	int defensor_nuevo;
	printf("ATENCION!! han ingresado la cantidad minima de orcos para agregar un defensor\n");
	printf("¿Desea agregar un defensor? (se le restaran 50 puntos de vida a la torre correspondiente\n");
	printf("enano: torre 1, elfo: torre 2)\n");
	printf("Y / N\n");
	scanf(" %c", &respuesta);
	while(letra_valida(respuesta) == false){
		printf("ERROR!!\n");
		printf("letra no valida.... \n");
		printf("Y / N\n");
		scanf(" %c", &respuesta);
	}
	if ((respuesta == AFIRMATIVO_MAY) && (juego->torres.enanos_extra > CONTADOR_INICIAL || juego->torres.elfos_extra > CONTADOR_INICIAL)){
		defensor_nuevo = juego->nivel.tope_defensores;
		printf("ingresar tipo de defensor: (G: ENANO, L: ELFO)\n");
		scanf(" %c", &juego->nivel.defensores[defensor_nuevo].tipo);
		while(tipo_valido(juego->nivel.defensores[defensor_nuevo].tipo, juego->nivel_actual) == false){
			printf("ERROR!!\n");
			printf("Tipo no valido.... \n");
			printf("ingresar tipo de defensor: (G: ENANO, L: ELFO)\n");
			scanf(" %c", &juego->nivel.defensores[defensor_nuevo].tipo);
		}
		agregar_ayudantes(&(*juego));

		if (juego->nivel.defensores[defensor_nuevo].tipo == 'G'){
			juego->torres.resistencia_torre_1 -= CONSE_DEF_EXTRA;
			juego->torres.enanos_extra -= 1;
		} else if(juego->nivel.defensores[defensor_nuevo].tipo == 'L'){
			juego->torres.resistencia_torre_2 -= CONSE_DEF_EXTRA;
			juego->torres.elfos_extra -= 1;
		}
		
		
	}else if (juego->torres.enanos_extra == CONTADOR_INICIAL ){
		printf("No quedan mas enanos en las torres");
	}else if(juego->torres.elfos_extra == CONTADOR_INICIAL){
		printf("No quedan mas elfos en las torres\n");
	}	
	system("clear");	
	mostrar_juego(*juego);
	
}
/*
PRE: el struct juego debe haberse completado con datos validos y coherentes.
POST: completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_1 (juego_t *juego){
	coordenada_t entrada_1;
	coordenada_t torre_1;
	torre_1.fil = FILA_TORRE_1_LVL_1;
	torre_1.col = COL_TORRE_1_LVL_1;

	entrada_1.fil = FILA_ENTRADA_LVL_1;
	entrada_1.col = COL_ENTRADA_LVL_1;
	obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
	presentar_nivel(juego->nivel_actual);
	mostrar_juego(*juego);
	while(juego->nivel.tope_defensores < MAX_DEF_PRIMER_LVL){
		agregar_ayudantes(&(*juego));		
	}	
}
/*
POST: se juega el primer nivel.
*/
void jugar_nivel_1 (juego_t *juego, int *preguntar_defensor_extra){
	
	while (estado_nivel(juego->nivel) == INCONCLUSO && estado_juego(*juego) == INCONCLUSO){
		jugar_turno(&(*juego));
		mostrar_juego(*juego);
			
		if(((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_1) == NULO) && *preguntar_defensor_extra > CONTADOR_INICIAL){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego));
		}
		detener_el_tiempo(0.5);
	}

}
/*
PRE: se debe haber completado con exito el primer nivel.
POST:se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_2(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra){
	system("clear");
	coordenada_t entrada_2;
	coordenada_t torre_2;
	juego->nivel_actual = SEGUNDO_NIVEL;
	nivel->max_enemigos_nivel = MAX_ENEMIGOS_SEGUNDO_LVL;
	torre_2.fil = FILA_TORRE_2_LVL_2;
	torre_2.col = COL_TORRE_2_LVL_2;

	entrada_2.fil = FILA_ENTRADA_LVL_2;
	entrada_2.col = COL_ENTRADA_LVL_2;

	juego->nivel.tope_camino_1 = CONTADOR_INICIAL;

	obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);
	nivel->tope_defensores = CONTADOR_INICIAL;
	nivel->tope_enemigos = CONTADOR_INICIAL;
	*preguntar_defensor_extra = PREG_LVL_BAJOS;
	presentar_nivel(juego->nivel_actual);
	system("clear");
	mostrar_juego(*juego);
	while(juego->nivel.tope_defensores < MAX_DEF_SEGUNDO_LVL){
		nivel->defensores[nivel->tope_defensores].tipo = ELFOS;
		agregar_ayudantes(&(*juego));
	}
	
}

/*
POST: se juega el segundo nivel.
*/
void jugar_nivel_2(juego_t *juego, int *preguntar_defensor_extra){
	
	while (estado_nivel(juego->nivel) == INCONCLUSO && estado_juego(*juego) == INCONCLUSO){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
			
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2 == NULO) && (*preguntar_defensor_extra > CONTADOR_INICIAL)){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego));
		}
		detener_el_tiempo(0.5);
	}
	
}
/*
PRE: se debe haber completado con exito el segundo nivel.
POST: se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_3(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra){
	system("clear");
	coordenada_t entrada_1;
	coordenada_t torre_1;
	coordenada_t entrada_2;
	coordenada_t torre_2;
	juego->nivel_actual = TERCER_NIVEL;
	nivel->max_enemigos_nivel = MAX_ENEMIGOS_TERCER_LVL;

	torre_1.fil = FILA_TORRE_1_LVL_3;
	torre_1.col = COL_TORRE_1_LVL_3;

	entrada_1.fil = FILA_ENTRADA_1_LVL_3;
	entrada_1.col = COL_ENTRADA_1_LVL_3;

	torre_2.fil = FILA_TORRE_2_LVL_3;
	torre_2.col = COL_TORRE_2_LVL_3;

	entrada_2.fil = FILA_ENTRADA_2_LVL_3;
	entrada_2.col = COL_ENTRADA_2_LVL_3;

	obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
	obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);

	nivel->tope_defensores = CONTADOR_INICIAL;
	
		
	nivel->tope_enemigos = CONTADOR_INICIAL;
	*preguntar_defensor_extra = PREG_LVL_3;
	presentar_nivel(juego->nivel_actual);
	system("clear");
	mostrar_juego(*juego);
	while(nivel->tope_defensores < MAX_DEF_TERCER_LVL){
		if (nivel->tope_defensores < MAX_DEF_TERCER_LVL / 2){
			nivel->defensores[nivel->tope_defensores].tipo = 'G';	
		}else {
			nivel->defensores[nivel->tope_defensores].tipo = 'L';
		}
		agregar_ayudantes(&(*juego));

	}

}
/*
POST: se juega el tercer nivel.
*/
void jugar_nivel_3(juego_t *juego, int *preguntar_defensor_extra){
	
	while((estado_nivel(juego->nivel) == INCONCLUSO) && (estado_juego(*juego) == INCONCLUSO)){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2) == NULO && *preguntar_defensor_extra > CONTADOR_INICIAL){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego));
		}
		detener_el_tiempo(0.25);
	}
}
/*
PRE: se debe haber completado con exito el tercer nivel.
POST: se completa el struct juego con los datos faltantes y necesarios para inciar el nivel.
*/
void iniciar_nivel_4(juego_t *juego, nivel_t *nivel, int *preguntar_defensor_extra){
	system("clear");
	coordenada_t entrada_1;
	coordenada_t torre_1;
	coordenada_t entrada_2;
	coordenada_t torre_2;
	juego->nivel_actual = CUARTO_NIVEL;
	nivel->max_enemigos_nivel = MAX_ENEMIGOS_CUARTO_LVL;

	torre_1.fil = FILA_TORRE_1_LVL_4;
	torre_1.col = COL_TORRE_1_LVL_4;

	entrada_1.fil = FILA_ENTRADA_1_LVL_4;
	entrada_1.col = COL_ENTRADA_1_LVL_4;

	torre_2.fil = FILA_TORRE_2_LVL_4;
	torre_2.col = COL_TORRE_2_LVL_4;

	entrada_2.fil = FILA_ENTRADA_2_LVL_4;
	entrada_2.col = COL_ENTRADA_2_LVL_4;

	obtener_camino(juego->nivel.camino_1, &(juego->nivel.tope_camino_1), entrada_1, torre_1);
	obtener_camino(juego->nivel.camino_2, &(juego->nivel.tope_camino_2), entrada_2, torre_2);

	nivel->tope_defensores = CONTADOR_INICIAL;
	nivel->tope_enemigos = CONTADOR_INICIAL;
	*preguntar_defensor_extra = PREG_LVL_4;
	presentar_nivel(juego->nivel_actual);
	system("clear");
	mostrar_juego(*juego);
	while(nivel->tope_defensores < MAX_DEF_CUARTO_LVL){
		if (nivel->tope_defensores < MAX_DEF_CUARTO_LVL / 2){
			nivel->defensores[nivel->tope_defensores].tipo = 'G';	
		}else {
			nivel->defensores[nivel->tope_defensores].tipo = 'L';
		}	
		agregar_ayudantes(&(*juego));

	}

}
/*
POST: se juega el cuarto nivel.
*/
void jugar_nivel_4 (juego_t *juego, int *preguntar_defensor_extra){
	
	while((estado_nivel(juego->nivel) == INCONCLUSO) && (estado_juego(*juego) == INCONCLUSO)){
		mostrar_juego(*juego);
		jugar_turno(&(*juego));
		if((cantidad_orcos_en_nivel(juego->nivel) % MIN_ORCOS_DEF_EXTRA_2) == NULO && *preguntar_defensor_extra > CONTADOR_INICIAL){
			*preguntar_defensor_extra -= 1;
			printf("la cantidad de preguntas que quedan son: %i \n", *preguntar_defensor_extra);
			agregar_ayudante_extra(&(*juego));
		}
		detener_el_tiempo(0.25);
	}
	
}


int main (){
	int viento;
	int humedad;
	char animo_legolas;
	char animo_gimli;
	juego_t juego;
	int preguntar_defensor_extra = PREG_LVL_BAJOS;
	char respuesta_menu;
	srand((unsigned)time(NULL));
	menu(&viento, &humedad, &animo_legolas, &animo_gimli, &respuesta_menu);
	inicializar_juego(&juego, viento, humedad, animo_legolas, animo_gimli);
	if(respuesta_menu != EXIT){
		iniciar_nivel_1 (&juego);
		jugar_nivel_1(&juego, &preguntar_defensor_extra);
	}
	if (estado_juego(juego) == INCONCLUSO && respuesta_menu != EXIT){
		iniciar_nivel_2(&juego, &(juego.nivel), &preguntar_defensor_extra);
		jugar_nivel_2(&juego, &preguntar_defensor_extra);				
	}
	if(estado_juego(juego) == INCONCLUSO && respuesta_menu != EXIT){
		iniciar_nivel_3(&juego, &(juego.nivel), &preguntar_defensor_extra);
		jugar_nivel_3(&juego, &preguntar_defensor_extra);
	}
	if(estado_juego(juego) == INCONCLUSO && respuesta_menu != EXIT){
		iniciar_nivel_4(&juego, &(juego.nivel), &preguntar_defensor_extra);
		jugar_nivel_4(&juego, &preguntar_defensor_extra);
	}
	if (estado_juego(juego) == DERROTA){
		system("clear");
		printf("Una de las torres ah sido destruida, los orcos invadieron con exito.\n");
		printf("Mas suerte la proxima!!\n");
	}
	if (estado_juego(juego) == VICTORIA ){
		system("clear");
		printf("Has defendido con exito las torres de las oleadas de orcos.\n");
		printf("Felicidades por ganar el juego!!!!!\n");
	}
return 0;
}