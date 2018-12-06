// guess.cc
// El programa genera un numero aleatorio y pide al usuario que lo adivine. Acaba cuando el usuario acierta el numero.

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int randNum, userNum;

	// time(NULL) devuelve "UNIX Epoch", es decir, el tiempo que ha pasado en segundos desde 00:00:00 1 Enero 1970
	// srand() usa el argumento recibido como semilla para generar un numero pseudo-aleatorio. 
	// Al usar time(NULL) el argumento cambia en cada segundo, por tanto, cada vez que llamemos a rand(), esta semilla cambia y 
	// generado sera distinto.
	srand(time(NULL)); 
	randNum = rand() % 11;	// si queremos generar un numero entre 0 y n, tenemos hacerlo modulo n+1, ya que n mod n = 0 

	cout << "Se ha generado un numero aleatorio. ¿Eres capaz de adivinarlo?" << endl;
	cin >> userNum;

	while(userNum != randNum) {
		cout << "Lo siento, no es el numero correcto. Vuelve a intentalo." << endl;
		cin >> userNum;
	}

	cout << "Correcto!!" << endl;
	return 0;

}
