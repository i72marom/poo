//crupier.h
//La clase crupier representa a una persona que es crupier y sus datos que lo diferencian

#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>
#include <iostream>
using namespace std;

class Crupier: public Persona{

private:

	string codigo_;
	
public:

	Crupier(string DNI, string codigo, string nombre="",string apellidos="",string direccion ="",string localidad="",string provincia="",string pais=""):                        Persona (DNI,nombre,apellidos,direccion,localidad,provincia,pais) {codigo_=codigo;};
	
	//set y get de la variable codigo
	inline string getCodigo() { return codigo_;};
	inline void setCodigo(string codigo){codigo_=codigo;};
};

#endif
