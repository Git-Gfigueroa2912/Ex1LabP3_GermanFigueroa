#include "Animatronic.h"

Animatronic::Animatronic(string nombre, int IA, int X, int Y, string mensaje) {
	nombre = nombre;
	IA = IA;
	posX = X;
	posY = Y;
	mensaje = mensaje;
}
string Animatronic::getNombre() {
	return nombre;
}
string Animatronic::getMensaje() {
	return mensaje;
}
int Animatronic::getIA() {
	return IA;
}
int Animatronic::getX() {
	return posX;
}
int Animatronic::getY() {
	return posY;
}
void Animatronic::setX(int X) {
	posX = X;
}
void Animatronic::setY(int Y) {
	posY = Y;
}
void Animatronic::setIA(int IA) {
	IA = IA;
}