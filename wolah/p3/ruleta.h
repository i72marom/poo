//ruleta.h
//La clase ruleta representa a una ruleta de casino y los elementos que la diferencia

#ifndef RULETA_H
#define RULETA_H

#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

#include "persona.h"
#include "crupier.h"
#include "jugador.h"
using namespace std;

class Ruleta {

private:
	int banca_;
	int bola_;
	list <Jugador> jugadores_;
	Crupier crupier_;
public:
	Ruleta(Crupier c):crupier_(c) {banca_=1000000; bola_=-1; srand(time(NULL));}	
	//set y get de la variable banca
	inline int getBanca(){return banca_;}
	bool setBanca(int banca);
	
	//set y get de la variable bola
	inline int getBola(){return bola_;}
	bool setBola(int bola);
	
	//set yget de la variable crupier
	inline Crupier getCrupier(){return crupier_;};
	inline void setCrupier(Crupier crupier){crupier_=crupier;};
	
	//get add delete lee y escribe de la variable jugadores
	inline list <Jugador> getJugadores(){return jugadores_;};
	bool addJugador (Jugador jugador);
	int deleteJugador(Jugador jugador);
	int deleteJugador (string DNI);
	void escribeJugadores();
	void leeJugadores();
	void giraRuleta();
	void getPremios();
	void tratarApuestas(Jugador &j,Apuesta a);
};
#endif
