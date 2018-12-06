// Juego.cc
// contiene la funcion principal del programa

#include <iostream>
#include <cstdlib>
#include "Dados.h"

using namespace std;

int main() {
	Dados dados;
	int dado1, dado2;

	// mostramos el valor inicial de los dados
	cout << "el valor inicial de los dados es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n\n";

	// Damos un valor a los dados y lo mostramos
	dados.lanzamiento();

	cout << "ahora el valor de los dados es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n";

	// pedimos un nuevo valor para los dados
	cout << "asigna un valor al dado1: ";
	cin >> dado1;
	cout << "asigna un valor al dado2: ";
	cin >> dado2;

	while (!dados.setDado1(dado1)) {
		cout << "El valor del dado 1 debe estar entre 1 y 6: ";
		cin >> dado1;
	}

	while (!dados.setDado2(dado2)) {
		cout << "El valor del dado 2 debe estar entre 1 y 6: ";
		cin >> dado2;
	}

	// nuevos valores de los dados y suma
	cout << "ahora el valor de los dados y la suma es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n";	
	cout << "\tsuma: " << dados.getSuma() << "\n";	
}
