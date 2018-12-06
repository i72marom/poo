// ruleta.cc
// autor: Manuel Mariscal
// practica 3
// ingenieria informatica - UCO
// Programacion orientada a objetos
// contiene las funciones de la clase

#include "ruleta.h"

Ruleta::Ruleta(Crupier crupier) : crupier_(crupier) {
	bola_ = -1;
	banca_ = 1000000;
	crupier_ = crupier;
}

bool Ruleta::addJugador(Jugador jugador) {

	// creaomos un iterador con la lista de jugadores
	// find busca dentro del iterador y devuelve el valor de la primera coincidencia
	// si no encuentra nada devuelve la ultima posicion
	list <Jugador> :: iterator it;
	it = find(jugadores_.begin(), jugadores_.end(), jugador); // begin indica el principio de la lista, end el final y jugador es lo que busca 
	if (it->getDNI() == jugador.getDNI()) { return false; }
	jugadores_.push_back(jugador); // push_back añade un elemento al final de la lista

	// abre un fichero y lo asocia al flujo de entrada
	ifstream fichero_entrada(jugador.getDNI()+".txt"); 
	fichero_entrada.close();

	return true;
}

int Ruleta::deleteJugador(string dni) {
	list <Jugador> :: iterator it; // crea el itrador para la lista de jugadores

	if (jugadores_.empty()) { return -1; } // la lista esta vacia

	// encuentra el dni y borra el jugador	
	for (it = jugadores_.begin(); it != jugadores_.end(); it++) {
		if (it->getDNI() == dni) {
			jugadores_.erase(it);
			return 1;
		}
	}

	return -2; // no encuentra el dni en la lista
}

void Ruleta::escribeJugadores() {
	list <Jugador> :: iterator it; // creamos el iterador para recorrer la lista de jugadores
	ofstream f("jugadores.txt"); // abre el fichero y lo asocia al flujo de salida

	// el bucle recorre toda la lista de jugadores para insertar los datos en el fichero
	for (it = jugadores_.begin(); it != jugadores_.end(); it++) {
		// el operador << funciona de la misma forma que en cout, envia los datos indicados al flujo de salida
		// sige el formato: DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
		f << it->getDNI() + ",";
		f << it->getCodigo() + ",";
		f << it->getNombre() + ",";
		f << it->getApellidos() + ",";
		f << it->getDireccion() + ",";
		f << it->getLocalidad() + ",";
		f << it->getProvincia() + ",";
		f << it->getPais() + ",";
		f << it->getDinero() + "\n";
	}
}
