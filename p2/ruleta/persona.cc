// persona.cc
// contiene las funciones de la clase, definidas en persona.h

#include "persona.h"

Persona::Persona(string dni, string nombre, string apellidos, int edad, string direccion, string localidad, string provincia, string pais) {
	dni_ = dni;
	nombre_ = nombre;
	apellidos_ = apellidos;
	direccion_ = direccion;
	localidad_ = localidad;
	provincia_ = provincia;
	pais_ = pais;
	edad_ = edad;
}
