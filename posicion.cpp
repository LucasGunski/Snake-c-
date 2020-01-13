#include "posicion.h";


Posicion::Posicion(int X, int Y)
{
	x = X;
	y = Y;
}

void Posicion::setRandomX(int maxX)
{
	x = rand() % maxX;
}

void Posicion::setRandomY(int maxY)
{
	y = rand() % maxY;
}

