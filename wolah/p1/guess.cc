//guess.cc
//Es un programa que genera un numero aleatorio entre 1 y 10
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void){

	int i,a;
	srand(time(NULL));
	i=(rand()%10)+1;
	do{
	std::cout << "Introduce un numero entre 1 y 10:\n";
	
	std::cin >> a;
	
		if(a==i){
			
		std::cout << "Has acertado!\n";
		
		}
		
		else {
		
		std::cout << "No has acertado, intentelo de nuevo\n";
		
			if(i<a){
			
			std::cout << "El numero a adivinar es mas pequeño\n";
			}
			
			else{
			
			std::cout << "El numero a adivinar es mas grande\n";
			}
		}
	}while (a!=i);
		
}
