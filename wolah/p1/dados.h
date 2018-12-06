//dados.h
//La clase dados representa el lanzamiento de dos dados
#ifndef DADOS_H
#define DADOS_H

class Dados{
private:

	int d1_, d2_,i_;
	int cont1_,cont2_;
	int suma1_,suma2_;
	int vd1_[5], vd2_[5];
public:
	Dados(); //el constructor no devuelve nada
	void lanzamiento();
	int getDado1();
	int getDado2();
	bool setDado1(int v1);
	bool setDado2(int v2);
	int getSuma();
	int getDiferencia();
	int getLanzamientos1();
	int getLanzamientos2();
	float getMedia1();
	float getMedia2();
	void rellenaVector1 ();
	void rellenaVector2 ();
	void getUltimo1(int *v);
	void getUltimo2(int *v);
};

#endif

