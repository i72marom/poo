// Dados.cc
// contiene las funciones de la clase dados

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "dados.h"

Dados::Dados() {
	dado1_ = 1;
	dado2_ = 1;
	cont1_ = 0;
	cont2_ = 0;
	sum1_ = 0;
	sum2_ = 0;
	srand(time(NULL)); 

	
	for (int i = 0; i < 5; ++i) {
		v1_[i] = 0;
		v2_[i] = 0;
	}
}

void Dados::lanzamiento() {
	dado1_ = (rand()%6)+1;
	dado2_ = (rand()%6)+1;
	cont1_++;
	cont2_++;
	sum1_ += dado1_;
	sum2_ += dado2_;
	rellenaVector1();
	rellenaVector2();
}

int Dados::getDado1() {
	return dado1_;
}

int Dados::getDado2() {
	return dado2_;
}

bool Dados::setDado1(int dado) {
	if (dado < 1 || dado > 6) { return false; }
	else {
		dado1_ = dado;
		cont1_++;
		sum1_ += dado1_;
		rellenaVector1();
		return true;
	}
}

bool Dados::setDado2(int dado) {
	if (dado < 1 || dado > 6) { return false; }
	else {
		dado2_ = dado;
		cont2_++;
		sum2_ += dado2_;
		rellenaVector2();
		return true;
	}
}

int Dados::getSuma() {
	return dado1_ + dado2_;
}

int Dados::getDiferencia() {
	return abs(dado1_ - dado2_);
}

int Dados::getLanzamientos1() {
	return cont1_;
}

int Dados::getLanzamientos2() {
	return cont2_;
}

float Dados::getMedia1() {
	if (cont1_ == 0) { return 0; }
	return (sum1_ / cont1_);
}

float Dados::getMedia2() {
	if (cont2_ == 0) { return 0; }
	return sum2_ / cont2_;
}

void Dados::rellenaVector1() {
	for (int i = 4; i > 0; i--) {
		v1_[i] = v1_[i-1];
	}
	v1_[0] = dado1_;
}

void Dados::rellenaVector2() {
	for (int i = 4; i > 0; i--) {
		v2_[i] = v2_[i-1];
	}
	v2_[0] = dado2_;
}

void Dados::getUltimos1(int *v) {
	for (int i = 0; i < 5; ++i) {
		v[i] = v1_[i];
	}
}

void Dados::getUltimos2(int *v) {
	for (int i = 0; i < 5; ++i) {
		v[i] = v2_[i];
	}
}
