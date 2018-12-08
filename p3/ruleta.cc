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

	for (it = jugadores_.begin(); it != jugadores_.end(); it++) {
		if (it->getDNI() == jugador.getDNI()) { return false; }
	}

	jugadores_.push_back(jugador); // push_back añade un elemento al final de la lista

	string playerFile = jugador.getDNI()+".txt";

	// ifstream abre un fichero y lo asocia al flujo de entrada
	// c_str() convierte el objeto string a un puntero c-string
	ofstream fichero_entrada(playerFile.c_str()); 
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

void Ruleta::leeJugadores() {
	char dni[20], codigo[20], nombre[20], apellidos[20], edad[20], direccion[20], localidad[20], provincia[20], pais[20];
	jugadores_.clear(); // clear (list) elimina el contenido de una lista
	string nomFich = "jugadores.txt";

	ifstream inputFile(nomFich); // abre un fichero y lo asocia al flujo de entrada

	// is_open() devuelve true si el fichero se ha abierto y se ha asociado al flujo de entrada
	if (!inputFile.is_open()) { cout << "Error al abrir el fichero.\n"; exit(-1); }

	// con inputFile.getline() se guarda lo leido en la variable
	while(inputFile.getline(dni, 20, ',')) { // getline devuelve false si ha acabado el fichero
		inputFile.getline(codigo, 20, ',');
		inputFile.getline(nombre, 20, ',');
		inputFile.getline(apellidos, 20, ',');
		inputFile.getline(edad, 20, ',');
		inputFile.getline(direccion, 20, ',');
		inputFile.getline(localidad, 20, ',');
		inputFile.getline(provincia, 20, ',');
		inputFile.getline(pais, 20, '\n');

		// se declara un objeto jugador pasandole como parametro los valores leidos en el fichero
		// con atoi() se convierten los char a int
		Jugador jugador(dni, codigo, nombre, apellidos, atoi(edad), direccion, localidad, provincia, pais);

		// push_back añade la el elemento recibido al final de la lista
		jugadores_.push_back(jugador);
	}

	// close() cierra el fichero
	// open() se usa para abrir el fichero en caso de que ifstream no reciba el nombre del fichero
	inputFile.close();
}
