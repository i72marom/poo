//juego.cc

#include <iostream>
#include <cstdlib>
#include "dados.h"

int main(void){
	Dados d;
	int v1, v2;

	d.lanzamiento();
	std::cout <<"\ndado1 = " << d.getDado1();
	std::cout <<"\ndado2 = " << d.getDado2();

//Asignar valor a los dados

	std::cout << "\nIntroduce los valores que deseas asignar al dado1 y al dado2\n";
	std::cin >> v1;
	std::cin >> v2;

	while(d.setDado1(v1)==false || d.setDado2(v2)==false){
		std::cout << "El numero debe estar comprendido entre 1 y 6\n";
		std::cin >> v1;
		std::cin >> v2;
}

//Valores después de asignarlos

	std::cout <<"\ndado1 = " << d.getDado1();
	std::cout <<"\ndado2 = " << d.getDado2();

	std::cout <<"\nsuma = " << d.getSuma();
	std::cout <<"\ndiferencia = " << d.getDiferencia();
	std::cout <<"\n";

return 0;


}
