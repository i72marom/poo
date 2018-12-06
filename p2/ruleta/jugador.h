// jugador.h
// define las funciones de la clase y contiene los
// comentarios sobre su funcionamiento

#ifndef JUGADOR_H
#define JUGADOR_H

	#include "persona.h"
	#include <list> // clase perteneciente a la stl (standard template library) http://www.cplusplus.com/reference/stl/
	#include <fstream> // cabecera que proviene de las clases de entrada/salida para trabajar con ficheros http://www.cplusplus.com/reference/fstream/

	typedef struct {
		int tipo;
		string valor;
		int cantidad;
	} Apuesta;

	class Jugador : public Persona {
		private:
			int dinero_;
			string codigo_;
			list <Apuesta> apuestas_;
		public:
			Jugador(string dni, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) { 
				codigo_ = codigo;
				dinero_ = 1000;
			}

			// modificadores y observadores para dinero
			inline void setDinero(int dinero) { dinero_ = dinero; }
			inline int getDinero() { return dinero_; }

			// modificadores y observadores para codigo	
			inline void setCodigo(string codigo) { codigo_ = codigo; }
			inline string getCodigo() { return codigo_; }
			
			// modificadores y observadores para apuestas
			inline list <Apuesta> getApuestas() { return apuestas_; }
			void setApuestas();
	};

#endif
