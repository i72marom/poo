// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests diferencia
TEST(Dados, Diferencia) {
  Dados d;
  
  EXPECT_EQ(abs(d.getDado1()-d.getDado2()), d.getDiferencia());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

// Tests numero de lanzamientos
	TEST(Dados, NumLanzamiento) {
	Dados d;
	EXPECT_EQ(0, d.getLanzamientos1());
	EXPECT_EQ(0, d.getLanzamientos2());
	for (int i=1; i<100; i++){
		d.lanzamiento();
		EXPECT_EQ(i, d.getLanzamientos1());
		EXPECT_EQ(i, d.getLanzamientos2());
	}
	d.setDado1(3);
	d.setDado2(15);
	EXPECT_EQ(100, d.getLanzamientos1());
	EXPECT_EQ(99, d.getLanzamientos2());
	d.setDado1(-3);
	d.setDado2(2);
	EXPECT_EQ(100, d.getLanzamientos1());
	EXPECT_EQ(100, d.getLanzamientos2());
}

// Tests media lanzamiento
	TEST(Dados, MediaLanzamiento) {
	Dados d;
	EXPECT_EQ(0, d.getMedia1());
	EXPECT_EQ(0, d.getMedia2());

	for (int i = 0; i < 100; ++i) {
		d.lanzamiento();
	}

	EXPECT_GE(6, d.getMedia1());
	EXPECT_LE(1, d.getMedia1());
}

// Tests media setDado
	TEST(Dados, MediaSetDado) {
	Dados d;
	EXPECT_EQ(0, d.getMedia1());
	EXPECT_EQ(0, d.getMedia2());

	for (int i = 1; i < 7; ++i) {
		d.setDado1(i);
		d.setDado2(i);
	}

	EXPECT_NEAR(d.getMedia1(), 3.5, 0.01);
	EXPECT_NEAR(d.getMedia2(), 3.5, 0.01);
}

// test getUltimos
TEST(Dados, getUltimos) {
	Dados d;
	int v_dado1[5];
	int v_dado2[5];

	for (int i = 0; i < 10; ++i) {
		d.setDado1(i);
		d.setDado2(i-5);
	}

	d.getUltimos1(v_dado1);
	d.getUltimos2(v_dado2);

	for (int i = 2; i < 7; ++i) {
		EXPECT_EQ(v_dado1[i-2], i);
		EXPECT_EQ((i-2), v_dado2[i-2]);
	}
}
