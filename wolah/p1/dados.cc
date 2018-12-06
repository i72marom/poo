//dados.cc
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"

Dados::Dados(){
	
	d1_=1;
	d2_=1;
	cont1_=0;
	cont2_=0;
	suma1_=0;
	suma2_=0;	
	srand(time(NULL));
		
	for(i_=0;i_<5;i_++){
		vd1_[i_]=0;	
		vd2_[i_]=0;
	}
}
void Dados::lanzamiento(){
	
	d1_=rand()%6+1;	
	d2_=rand()%6+1;
	
	cont1_++;
	cont2_++;
	
	suma1_=suma1_+d1_;
	suma2_=suma2_+d2_;
	
	rellenaVector1();
	rellenaVector2();
	
}

int Dados::getDado1(){

	return d1_;
	}

int Dados::getDado2(){

	return d2_;
	}

bool Dados::setDado1(int v1){

	
	
	if(v1<1 || v1>6){return false;}
	else{
	d1_=v1;
	suma1_=suma1_+d1_;
	cont1_++;
	rellenaVector1();
	
	return true;
	}
}

bool Dados::setDado2(int v2){
	
	
	
	if(v2<1 || v2>6){return false;}
	else{
	d2_=v2;
	suma2_=suma2_+d2_;
	cont2_++;
	rellenaVector2();
	return true;
	}
}

int Dados::getSuma(){

	return d1_+d2_;
	}

int Dados::getDiferencia(){

	if(d1_>d2_){
	return d1_-d2_;
	}else{
	return d2_-d1_;
	}
}

int Dados::getLanzamientos1(){

	return cont1_;	
}

int Dados::getLanzamientos2(){

	return cont2_;
}

float Dados::getMedia1(){
	
	if (cont1_==0){
		return 0;
	}
	else{ return suma1_/(float)cont1_;}
}
		
float Dados::getMedia2(){
	
	if (cont2_==0){
		return 0;
	}
	else{ return suma2_/(float)cont2_;}
}		

void Dados::rellenaVector1 (){
	
	int i;
	
	for(i=4;i>=0;i--){
	vd1_[i]=vd1_[i-1];
	}
	vd1_[0]=d1_;
}

void Dados::rellenaVector2 (){
	
	int i;
	
	for(i=4;i>=0;i--){
	vd2_[i]=vd2_[i-1];
	}
	vd2_[0]=d2_;
}

void Dados::getUltimo1(int *v){

	int i;
	
	for(i=0;i<5;i++){
	
	v[i]=vd1_[i];
	}
}

void Dados::getUltimo2(int *v){

	int i;
	
	for(i=0;i<5;i++){
	
	v[i]=vd2_[i];
	}
}
