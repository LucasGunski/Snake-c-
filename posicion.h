#pragma once

#include <iostream>

using namespace std;


class Posicion
{
public:
	int x;
	int y;
	Posicion(int X = 0, int Y = 0);

	void setRandomX(int maxX);
	void setRandomY(int maxY);
};