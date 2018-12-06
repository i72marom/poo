#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	string nombre = "prueba.txt";
	// remove(nombre); // remove pertenece a cstdio y devuelve 0 si ha borrado el fichero
	ofstream f(nombre); // abre el fichero y lo asocia al flujo de salida

	if (!f.is_open()) { cout << "error\n"; exit(-1); }

	f << "caca\n";

	f.close();
}
