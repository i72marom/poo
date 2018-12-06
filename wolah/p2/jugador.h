//jugador.h
//La clase jugador representa a un jugador y sus datos que lo diferencian

#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
struct Apuesta{

	int tipo;
	string valor;
	int cantidad;
};


using namespace std;

class Jugador: public Persona{

private:
	
	int dinero_;
	string codigo_;
	list <Apuesta> apuestas_;

public:

	Jugador(string DNI,string codigo,string nombre="",string apellidos="",string direccion ="",string localidad="",string provincia="",string pais=""):Persona(DNI,nombre,apellidos,direccion,localidad,provincia,pais) {
	
	codigo_=codigo;
	dinero_=1000;
	};
	
	//set y get de la variable codigo
	inline string getCodigo (){ return codigo_;};
	inline void setCodigo (string codigo){codigo_=codigo;};
	
	//set y get de la variable dineroç
	inline int getDinero (){ return dinero_;};
	inline void setDinero (int dinero){dinero_=dinero;};
	
	//get de la lista apuestas
	inline list <Apuesta> getApuestas(){return apuestas_;};
	void setApuestas();	


}; 
	
#endif
