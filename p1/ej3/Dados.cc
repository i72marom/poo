// Dados.cc
// contiene las funciones de la clase dados

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dados.h"

//el constructor Dados() se ejecuta una sola vez y no devuelve nada
Dados::Dados() {
	dado1_ = 1;
	dado2_ = 1;
	srand(time(NULL)); // la semilla se puede declarar en el constructor porque solo se declara una vez
}

void Dados::lanzamiento() {
	dado1_ = (rand()%6)+1;
	dado2_ = (rand()%6)+1;
}

int Dados::getDado1() {
	return dado1_;
}

int Dados::getDado2() {
	return dado2_;
}

bool Dados::setDado1(int dado) {
	if (dado < 1 || dado > 6) { return false; }
	else { dado1_ = dado; return true;}
}

bool Dados::setDado2(int dado) {
	if (dado < 1 || dado > 6) { return false; }
	else { dado2_ = dado; return true;}
}

int Dados::getSuma() {
	return dado1_ + dado2_;
}
