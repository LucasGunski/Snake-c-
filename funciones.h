#pragma once


#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include "posicion.h"




//Constantes

const int ANCHO = 30;
const int ALTO = 15;
const int CANTRONDAS = 16;
//int ronda;
enum direcciones
{
	DETENIDO = 0, IZQUIERDA, DERECHA, ARRIBA, ABAJO
};

// VARIABLES GLOBALES


extern bool gameOver;
extern int x, y, puntaje;
extern int contadorFramerate;
extern Posicion posPalabra1, posPalabra2;
extern direcciones direccion;
extern int framerate;
extern int contador;
extern bool finInicio;

extern int colaX[100];
extern int colaY[100];
extern int nCola;

//============================================================
// DECLARACION DE LAS FUNCIONES GLOBALES
//============================================================
void setup();
void update();
void draw();
void input();
void menuInicio();
//---