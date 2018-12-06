// jugador.cc
// contiene las funciones de la clase, definidas en jugador.h

#include "jugador.h"

void Jugador::setApuestas() {
	char tipo[10], valor[10], cantidad[10];
	Apuesta bet;
	apuestas_.clear(); // clear (list) elimina el contenido de una lista
	string nombre_fichero = getDNI() + ".txt";

	ifstream fichero_entrada(nombre_fichero); // abre un fichero y lo asocia al flujo de entrada

	if (fichero_entrada.is_open()) { // is_open() devuelve true si el fichero se ha abierto y se ha asociado al flujo de entrada
		
		// con fichero_entrada.getline() se guarda lo leido en la variable
		while(fichero_entrada.getline(tipo, 10, ',')) { // getline devuelve false si ha acabado el fichero
			fichero_entrada.getline(valor, 10, ',');
			fichero_entrada.getline(cantidad, 10, '\n');

			// se guardan los valores leidos en la estructura
			// con atoi() se convierten los char a int
			bet.tipo = atoi(tipo);
			bet.valor = valor;
			bet.cantidad = atoi(cantidad);

			// push_back añade la el elemento recibido al final de la lista
			apuestas_.push_back(bet);
		}

		// close() cierra el fichero
		// open() se usa para abrir el fichero en caso de que
		// ifstream no reciba el nombre del fichero
		fichero_entrada.close();
	} else { // si is_open devuelve false, se muestra un mensaje de error y finaliza el programa
		cout << "Error al abrir el fichero.\n";
		exit(-1);
	}
}
