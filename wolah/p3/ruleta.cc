//ruleta.cc
//metodos de la clase ruleta
#include "ruleta.h"

using namespace std;

bool Ruleta::setBanca(int banca){

	if(banca<0){return false;}
	
	else{
		banca_=banca;
		return true;
	}
}

bool Ruleta::setBola (int bola){

	if (bola<0 || bola>36){return false;}
	
	else{
		bola_=bola;
		return true;
	}
}

bool Ruleta::addJugador(Jugador jugador){

	list<Jugador>::iterator i;
	
	
	for(i=jugadores_.begin();i!=jugadores_.end();i++)
		if(i->getDNI()==jugador.getDNI())return false;
		
        jugadores_.push_back(jugador);
	
	string nomfich=(jugador.getDNI()+".txt");
	ifstream fich(nomfich.c_str());
	
	if(!fich){
		ofstream(nomfich.c_str());
	}
	
	fich.close();
	return true;		
}

int Ruleta::deleteJugador(Jugador jugador){
	return deleteJugador(jugador.getDNI());
}

int Ruleta::deleteJugador(string DNI){

	list <Jugador>::iterator i;
	
	if(jugadores_.empty()==true){
	return -1;
	}

	for(i=jugadores_.begin();i!=jugadores_.end();i++){
	
		if(i->getDNI()==DNI){
			jugadores_.erase(i);
			return 1;
		}
	
	}
	
	return -2;
}

void Ruleta::escribeJugadores(){

	list <Jugador>::iterator i;
	ofstream fichero;
	fichero.open("jugadores.txt");
	
	for(i=jugadores_.begin();i!=jugadores_.end();i++){
	
		fichero<<i->getDNI()+",";
		fichero<<i->getCodigo()+",";
		fichero<<i->getNombre()+",";
		fichero<<i->getApellidos()+",";
		fichero<<i->getDireccion()+",";
		fichero<<i->getLocalidad()+",";
		fichero<<i->getProvincia()+",";
		fichero<<i->getPais()+",";
		fichero<<i->getDinero()<<endl;
		
	}
	
	fichero.close();
}

void Ruleta::leeJugadores(){

	ifstream fichero;
	fichero.open("jugadores.txt");
	string cadaux;
	Jugador aux("dni","cod");
	jugadores_.clear();
	
	while(getline(fichero,cadaux,',') && !fichero.eof()){
	
		aux.setDNI(cadaux);
		getline(fichero, cadaux, ',');
		aux.setCodigo(cadaux);
		getline(fichero, cadaux, ',');
		aux.setNombre(cadaux);
		getline(fichero, cadaux, ',');
		aux.setApellidos(cadaux);
		getline(fichero, cadaux, ',');
		aux.setDireccion(cadaux);
		getline(fichero, cadaux, ',');
		aux.setLocalidad(cadaux);
		getline(fichero, cadaux, ',');
		aux.setProvincia(cadaux);
		getline(fichero, cadaux, ',');
		aux.setPais(cadaux);
		getline(fichero, cadaux, '\n');
		aux.setDinero(atoi(cadaux.c_str()));
		
		jugadores_.push_back(aux);
	}

	fichero.close();	
}

void Ruleta::giraRuleta(){

	int auxbola;

	auxbola=rand()%37;
	setBola(auxbola);
}

void Ruleta::getPremios(){

	list <Apuesta>::iterator iap;
	list <Jugador>::iterator ijug;
	list <Apuesta> aux;
	
	for(ijug=jugadores_.begin(); ijug!=jugadores_.end(); ijug++){
		//se cargan las apuestas del jugador ijug en la lista aux de apuestas 
		ijug->setApuestas();
		aux=ijug->getApuestas();
	
		//se recorren estas apuestas y se tratan para hacer el reparto de ganancias/perdidas.
		for(iap=aux.begin(); iap!=aux.end();iap++)			
			tratarApuestas(*ijug,*iap);	
	}
}

void Ruleta::tratarApuestas(Jugador &j,Apuesta a){

	int opcion=a.tipo;

	switch (opcion){

		case 1: if(atoi(a.valor.c_str())==getBola()){//Si aciertas el numero ganas el 36.00 de lo que apuestas
		
			j.setDinero((j.getDinero()+(35*a.cantidad)));
			setBanca((getBanca()-35*a.cantidad));
		}
			else{ //y si pierdes pierdes lo apostado y lo gana la banca			
				j.setDinero((j.getDinero()-a.cantidad));
				setBanca((getBanca()+a.cantidad));
			}
		break;
	
		case 2:	if(getBola()==0){ //si sale el cero lo pierdes todo lo que hayas apostado
		
			j.setDinero(j.getDinero()-a.cantidad);
			setBanca(getBanca()+a.cantidad);
		}
			else{ //pero si no sale y aciertas color ganas 2.0 de lo que apuestes
				if((a.valor=="negro" && ((getBola()%2 + ((getBola()/10)%2))%2)==1 )||(a.valor=="rojo"  && ((getBola()%2 + ((getBola()/10)%2))%2)==0)){
		
					j.setDinero(j.getDinero()+a.cantidad);
					setBanca(getBanca()-a.cantidad);
				}
		
				else{ //y si no aciertas color pierdes lo apostado
		
					j.setDinero(j.getDinero()-a.cantidad);
					setBanca(getBanca()+a.cantidad);
				}	
			}
		break;
	
		case 3:	if(getBola()==0){//si la bola sale cero pierdes lo apostado
		
			j.setDinero(j.getDinero()-a.cantidad);
			setBanca(getBanca()+a.cantidad);
		}
		
				else{ //y si no sale cero y aciertas par/impar ganas 2.0 y la banca lo pierde
					if((a.valor=="par" && getBola()%2==0) || (a.valor =="impar" && getBola()%2==1)){
		
					j.setDinero(j.getDinero()+a.cantidad);
					setBanca(getBanca()-a.cantidad);	
					}
					else{//y si no aciertas pierdes lo apostado
				
						j.setDinero(j.getDinero()-a.cantidad);
						setBanca(getBanca()+a.cantidad);
					}
				}
		break;
	
	
		case 4: if(getBola()==0){//si la bola sale 0 pierdes lo apostado
			
			j.setDinero(j.getDinero()-a.cantidad);
			setBanca(getBanca()+a.cantidad);
		}
		else{//y si no y aciertas si es bajo o alto ganas 2.0 de tus apuestas
			if((a.valor=="bajo" && (getBola()>=1 && getBola()<=18)) || ((a.valor=="alto" && (getBola()>=19 && getBola()<=36)))){
		
			j.setDinero(j.getDinero()+a.cantidad);
			setBanca(getBanca()-a.cantidad);
			
			}
			else{//pero si no aciertas pierdes lo apostado y lo gana la banca
		
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
		}
	break;
	
	default: cout<< "Error en la apuesta";
	exit(-1);
	}
}




