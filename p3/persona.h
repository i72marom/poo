// persona.h
// define las funciones de la clase y contiene los
// comentarios sobre su funcionamiento

#ifndef PERSONA_H
#define PERSONA_H

	#include <string> // cabecera que introduce el tipo string y funciones para su tratamiento http://www.cplusplus.com/reference/string/ 
	#include <iostream> // E/S estandar http://www.cplusplus.com/reference/iostream/

	using namespace std;
	
	class Persona {
		private:
			int edad_;
			string dni_, nombre_, apellidos_, direccion_;
			string localidad_, provincia_, pais_;
		public:
			// el constructor Persona() se ejecuta una sola vez y no devuelve nada
			// Inicializamos las variables privadas
			Persona(string dni, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="");

			// modificadores: establecen un nuevo valor para cada variable.
			// inline indica al compilador que debe sustituir la llamada a una funcion
			// por el codigo de la misma cada vez que se realice dicha llamada
			inline void setDNI(string dni) { dni_ = dni; }
			inline void setNombre(string nombre) { nombre_ = nombre; }
			inline void setApellidos(string apellidos) { apellidos_ = apellidos; }
			inline void setDireccion(string direccion) { direccion_ = direccion; }
			inline void setLocalidad(string localidad) { localidad_ = localidad; }
			inline void setProvincia(string provincia) { provincia_ = provincia; }
			inline void setPais(string pais) { pais_ = pais; }
			
			// set edad debe comprobar que el parametro recibido sea un entero positivo
			inline bool setEdad(int edad) {
				if (edad < 0) { return false; }
				else { edad_ = edad; return true; }
			}

			// observadores: devuelven el valor de la variable en ese momento
			inline string getDNI() { return dni_; }
			inline string getNombre() { return nombre_; }
			inline string getApellidos() { return apellidos_; }
			inline string getDireccion() { return direccion_; }
			inline string getLocalidad() { return localidad_; }
			inline string getProvincia() { return provincia_; }
			inline string getPais() { return pais_; }
			inline int getEdad() { return edad_; }

			// string getApellidosyNombre();
			// metodo que devuelve los apellidos y el nombre en 
			// formato "Apellidos, Nombre" usando la concatenacion
			// de la clase string
			inline string getApellidosyNombre() { return apellidos_ + ", " + nombre_; }

			// bool mayor();
			// devuelve si una persona es mayor de edad
			inline bool mayor() {
				if (edad_ > 17) { return true; }
				return false;
			}
	};

#endif