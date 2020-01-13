#include "funciones.h"
#include "posicion.h"

#include <iostream>

using namespace std;

//VariablesGobales

bool gameOver;
bool intro;
int x, y, puntaje;
Posicion posPalabra1, posPalabra2;

int contadorFramerate;
string palabras1[] = { "se miran", "se olfatean" , "se palpan" ,"se presienten", "se apresan","se enlazan","se chupan","se entregan" };
string palabras2[] = { "se repelen", "se estiran", "se aparecian" , "se atraviesan" , "se incrustan","se desgarran","se refiregn","se\32injertan" };
string frase;

direcciones direccion;

int framerate;
int contador;
int ronda;
int colaX[100];
int colaY[100];
int OpcionIntro;
int nCola;
bool finInicio = true;

//FuncionesGlobales

void menuInicio()
{
	int OpcionIntro;
	{   
		cout << "                       Yo  no   se   nada" << endl;
		cout << "                       Tu  no sabes  nada" << endl;
		cout << "                       Ud  no  sabe  nada" << endl;
		cout << "                       El  no  sabe  nada" << endl;
		cout << "                       Ellos no sabennada" << endl;
		cout << "                       Ellos no sabennada" << endl;
		cout << "                       Uds no saben  nada" << endl;
		cout << "                     Nosotros no sabemos nada." << endl << endl;

		cout << "    La desorientacion de mi generacion tiene su explicacion en la" << endl;
		cout << "    direccion de nuestra educacion,cuya idealizacion de la accion" << endl;
		cout << "    era --!sin discusion!--una mistificacion en contradiccion con" << endl;
		cout << "            nuestra propension a la meditacion,a la" << endl;
		cout << "                contemplacion y a la masturbacion" << endl;
		cout << "                 (Gutural, lo mas guturalmente" << endl;
		cout << "                   que se pueda).Creo que creo" << endl;
		cout << "                    Y creo que no creo en" << endl;
		cout << "                     lo que creo que creo." << endl << endl<<endl;
		cout << "                       ***            ***" << endl;
		cout << "                          BIENVENIDOS A: " << endl << endl;

		cout << "                     ++   Girondo´s Snake    ++"<<endl<<endl;

		cout << "                        ***            ***" << endl<< endl;

		cout << "                        Y Y ?A  ?A Y Y" << endl;
		cout << "                     su ba lli  lla su ba" << endl;
		cout << "                    bo jo es      es bo jo" << endl;
		cout << "                las las ta?         ? las las" << endl;
		cout << "               es es !A               !A es es" << endl;
		cout << "             ca ca qui                  ca ca ca" << endl;
		cout << "           ñe ñe no                       es ras ras" << endl;
		cout << "      arri aba ta                           ta arri aba" << endl;
		cout << "!... ba... jo....                              ba...! jo...! !..." << endl;
		
		system("pause");
		system("cls");
	

		
		cout << endl<< endl<< endl<< endl;

		cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW     Oliverio-s Snake   wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
		cout << "   WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWwW                        WWWWWWWWwwWWWWWWWWWWWWWWWWWWWWWW" << endl;
		cout << "          WWWWWWWWWWWWWWWWWWWWWWWWW                        WWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
		cout << "          W                         1-     Instrucciones                                    W          " << endl;
		cout << "          O                         2-     Comenzar                                         O        " << endl;
		cout << "          M                         3-     Salir                                            M       " << endl;
		cout << "          MMMMMMMMMMMMMMMMMMMMMMMM                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM        " << endl;
		cout << "    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
		cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
		cout << "                                Eleliga una opcion y precione Enter:                                               " << endl;
		cout << "                                 "; cin >> OpcionIntro;

		system("cls");

		switch (OpcionIntro)
		{
		case 1:
			cout << " Ayuda a la serpiente Oliverio a elegir y recolectar las 6 frases que formaran" << endl;
			cout << "el poema 12++" << endl<<endl;

			cout << " Utilize las flechas  para moverse hacia Arriba Abajo Izquierda o Derecha" << endl << endl;
			cout << " Eliga una de las frases que quiera incluir en su frase final" << endl;
			cout << " situandose sobre la pimera letra de la frase que se imprime en el tablero" << endl << endl;

			cout << " Ten cuidado de no colisionar contra ti mismo" << endl;
			cout << " Ten cuidado de no perderte en el tablero ;)";
			system("pause");
			system("cls");
			break;
		case 2:
			finInicio = false;
			break;
		case 3:
			exit(EXIT_FAILURE);
		default:
			break;
		}

		system("pause");

	}
}

void setup()
{

	srand(time(NULL));
	gameOver = false;
	direccion = DETENIDO;
	x = ANCHO / 2;
	y = ALTO / 2;


	posPalabra1.setRandomX(ANCHO);
	posPalabra1.setRandomY(ALTO);
	posPalabra2.setRandomX(ANCHO);
	posPalabra2.setRandomY(ALTO);
	puntaje = 0;
	frase = "";
	
	if (posPalabra1.x + palabras1[0].size() > ANCHO)
	{
		posPalabra1.x -= posPalabra1.x + palabras1[0].size() - ANCHO;
	}
	if (posPalabra2.x + palabras2[0].size() > ANCHO)
	{
		posPalabra2.x -= posPalabra2.x + palabras2[0].size() - ANCHO;
	}
	framerate = 2;
	contador = 0;
	ronda = 0;
}

void update()
{
	if (contador % framerate == 0)
	{
		for (int i = nCola; i > 0; i--)
		{
			colaX[i] = colaX[i - 1];
			colaY[i] = colaY[i - 1];
		}

		colaX[0] = x;
		colaY[0] = y;

		switch (direccion)
		{
		case IZQUIERDA:
			x--;
			break;
		case DERECHA:
			x++;
			break;
		case ARRIBA:
			y--;
			break;
		case ABAJO:
			y++;
			break;
		default:
			break;
		}

		for (int i = 0; i < nCola; i++)
		{
			if (colaX[i] == x && colaY[i] == y)
			{
				gameOver = true;
			}
		}

		if (x == ANCHO) x = 1;
		else if (x == 0) x = ANCHO - 1;

		if (y == ALTO) y = 1;
		else if (y == 0) y = ALTO - 1;

		if (ronda == CANTRONDAS) gameOver = true;

		if ((x == posPalabra1.x && y == posPalabra1.y) || (x == posPalabra2.x && y == posPalabra2.y))
		{
			if (x == posPalabra1.x && y == posPalabra1.y)
				frase += palabras1[ronda] + " ";
			else
				frase += palabras2[ronda] + " ";

			ronda++;
			puntaje += 10;

			
			posPalabra1.setRandomX(ANCHO);
			posPalabra1.setRandomY(ALTO);
			
			if (posPalabra1.x + palabras1[ronda].size() > ANCHO)
			{
				posPalabra1.x -= posPalabra1.x + palabras1[ronda].size() - ANCHO;
			}

			posPalabra2.setRandomX(ANCHO);
			posPalabra2.setRandomY(ALTO);
			if (posPalabra1.y == posPalabra2.y)
				posPalabra2.setRandomY(ALTO);

			
			if (posPalabra2.x + palabras2[ronda].size() > ANCHO)
			{
				posPalabra2.x -= posPalabra2.x + palabras2[ronda].size() - ANCHO;
			}
			nCola++;
		}
		
	}
	contador++;
	system("cls");
	cout << frase;

}

void draw()
{
	system("cls");

	for (int fila = 0; fila <= ALTO; fila++)
	{
		for (int columna = 0; columna <= ANCHO; columna++)
		{
			if (fila == 0 || fila == ALTO)
			{
				cout << "W";
			}
			else if (columna == 0 || columna == ANCHO)
			{
				cout << frase;
			}
			else if (columna == x && fila == y)
			{
				cout << "O";
			}
			else if (columna == posPalabra1.x && fila == posPalabra1.y)
			{

 				cout << palabras1[ronda];
			}
			else if (columna == posPalabra2.x && fila == posPalabra2.y)
			{
				cout << palabras2[ronda];
			}
			else
			{
				bool hayCola = false;

				for (int i = 0; i < nCola; i++)
				{
					if (colaX[i] == columna && colaY[i] == fila)
					{
						cout << "*-";
						hayCola = true;
					}
				}
				if (!hayCola) cout << " ";
			}
		}
		cout << endl;
	}

	cout << endl;
	
	cout << "Frase:" << frase << endl;
	cout << ronda << endl;

	while (ronda == 7)
	{
		
		system("cls");
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase <<endl;
		cout << frase << frase << frase << frase <<endl;
		cout << frase << frase << frase << frase <<endl;
		cout << frase << frase << frase << frase <<endl;
		cout << frase << frase << frase << frase <<endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		cout << frase << frase << frase << frase << endl;
		
		system("pause");
		
		
		
	}
	
}
	


void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75:
			direccion = IZQUIERDA;
			break;
		case 77:
			direccion = DERECHA;
			break;
		case 72:
			direccion = ARRIBA;
			break;
		case 80:
			direccion = ABAJO;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
	}

}