#include <iostream>
#include "funciones.h"

using namespace std;

//============================================================
// MAIN
//============================================================

int main()
{
	while (finInicio || gameOver)
	{
	
		menuInicio();

	}

	setup();
	

	while (!gameOver)
	{
		
		draw();
		input();
		update();
	}

	cout << "Game Over!" << endl;
	cout << endl;
	system("pause");
	return 0;
}