#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <string>

using namespace std;

class Animatronic {
private:
	string nombre;
	int nivel_IA;
	string mensaje;
	int posX;
	int posY;

	void setX(int X);
	void setY(int Y);
	void setIA(int IA);
};
#endif


