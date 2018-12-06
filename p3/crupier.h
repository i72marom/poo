// crupier.h
// define las funciones de la clase y contiene los
// comentarios sobre su funcionamiento

#ifndef CRUPIER_H
#define CRUPIER_H

	#include "persona.h"

	class Crupier : public Persona {
		private:
			string codigo_;
		public: 
			Crupier(string dni, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) { codigo_ = codigo; }

			inline void setCodigo(string codigo) { codigo_ = codigo; }
			inline string getCodigo() { return codigo_; }
	};

#endif
