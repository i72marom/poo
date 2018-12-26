// Juego.cc
// contiene la funcion principal del programa
#include "dados.h"


int main() {
	Dados dados;
	int dado1, dado2;
	int v_dado1[5], v_dado2[5];

	// mostramos el valor inicial de los dados
	cout << "el valor inicial de los dados es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n\n";

	// valor inicial del numero de veces que se han lanzado los dados
	cout << "El dado 1 se ha lanzado " << dados.getLanzamientos1() << " veces.\n";
	cout << "El dado 2 se ha lanzado " << dados.getLanzamientos2() << " veces.\n";

	// Damos un valor a los dados y lo mostramos
	dados.lanzamiento();

	cout << "ahora el valor de los dados es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n";

	// bucle para pedir un nuevo valor hasta que el usuario indique la salida
	while (true) {
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

		char salida;
		cout << "¿Desea continuar lanzando? (y/n): ";
		cin >> salida;
		while (salida != 'n' && salida != 'y') { 
			cout << salida << " no es una opcion reconocida. ¿Desea continuar lanzando? (y/n): ";
			cin >> salida;
		}
		if (salida == 'n') { break; }
	}

	// valor actual del numero de veces que se han lanzado los dados
	cout << "El dado 1 se ha lanzado " << dados.getLanzamientos1() << " veces.\n";
	cout << "El dado 2 se ha lanzado " << dados.getLanzamientos2() << " veces.\n";

	// nuevos valores de los dados y suma
	cout << "ahora el valor de los dados y la suma es:\n";
	cout << "\tdado1: " << dados.getDado1() << "\n";
	cout << "\tdado2: " << dados.getDado2() << "\n";	
	cout << "\tsuma: " << dados.getSuma() << "\n";
	cout << "El valor de la diferencia es: " << dados.getDiferencia() << endl;

	// Media para los lanzamientos de los dados
	cout << "La media del dado 1 es " << dados.getMedia1() << " y la del dado 2 es " << dados.getMedia2() << "\n";

	// Ultimos 5 lanzamientos de los dados
	dados.getUltimos1(v_dado1);
	dados.getUltimos2(v_dado2);
	cout << "Los 5 ultimos valores de los dados son: \n";
	cout << "\tdado1: ";
	for (int i = 0; i < 5; i++) {
		cout << v_dado1[i];
		if (i != 4) { cout << ", "; }
		else { cout << "\n"; }
	}
	cout << "\tdado2: ";
	for (int i = 0; i < 5; i++) {
		cout << v_dado2[i];
		if (i != 4) { cout << ", "; }
		else { cout << "\n"; }
	}
}
