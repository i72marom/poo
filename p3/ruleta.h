// ruleta.h
// autor: Manuel Mariscal
// practica 3
// ingenieria informatica - UCO
// Programacion orientada a objetos
// define las funciones de la clase y contiene los comentarios sobre su funcionamiento

#ifndef RULETA_H
#define RULETA_H

	#include "crupier.h"
	#include "jugador.h"
	#include <algorithm> // define funciones para ser usadas en un rango de elementos http://www.cplusplus.com/reference/algorithm/

	class Ruleta {
		private:
			int banca_, bola_;
			list <Jugador> jugadores_;
			Crupier crupier_;
		public:
			Ruleta(Crupier crupier);
		
			// observadores;
			inline int getBanca() { return banca_; }
			inline int getBola() { return bola_; }
			inline Crupier getCrupier() { return crupier_; }
			inline list <Jugador> getJugadores() { return jugadores_; }

			// modificadores
			inline void setCrupier(Crupier crupier) { crupier_ = crupier; }

			// setBanca() Solo admite valores positivos. En caso contrario devuelve false.
			inline bool setBanca(int banca) {
				if (banca < 0) { return false; }
				banca_ = banca;
				return true;
			}

			// setBola() Solo admite valores entre 0 y 36. En caso contrario devuelve false.
			inline bool setBola(int bola) {
				if (bola < 0 || bola > 36) { return false; }
				bola_ = bola;
				return true;
			}

			// bool addJugador() 
			// Recibe un jugador como parámetro y añade el jugador al final de la lista de jugadores 
			// y crea un fichero tipo texto de apuestas vacío y devuelve true. El fichero debe llamarse 
			// DNI.txt, siendo DNI el DNI del jugador. Si el fichero ya existe, lo deja como estaba sin 
			// modificarlo ni borrarlo. Si ya existe en la lista un jugador con ese DNI el método no hace nada y devuelve false.
			bool addJugador(Jugador jugador);

			// int deleteJugador()
			// recibe el DNI de un jugador y borra de la lista de jugadores el jugador con ese DNI. Debe devolver 1 si 
			// se ha borrado al jugador, -1 si la lista está vacía y -2 si el DNI no se ha encontrado en la lista de 
			// jugadores. No debe borrar el fichero con las apuestas de ese jugador.
			int deleteJugador(string dni);

			// int deleteJugador()
			// recibe un objeto de la clase jugador y borra de la lista de jugadores el jugador con ese DNI. Debe devolver 1 si 
			// se ha borrado al jugador, -1 si la lista está vacía y -2 si el DNI no se ha encontrado en la lista de 
			// jugadores. No debe borrar el fichero con las apuestas de ese jugador.
			inline int deleteJugador(Jugador jugador) { return deleteJugador(jugador.getDNI()); }

			// El método void escribeJugadores() escribe los datos de la lista de jugadores en un fichero texto denominado 
			// jugadores.txt. Cada vez que se escribe este fichero se borra todo su contenido anterior. El formato de este archivo debe ser:
			//		DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
			// Si alguno de los campos está vacío el fichero quedaría de la forma:
			//		DNI,código,nombre,apellidos,,,,,dinero
			// recordar que DNI y código de jugador es obligatorio en Jugador
			void escribeJugadores();

			// El método void leeJugadores() lee los datos de los jugadores del fichero jugadores.txt y los mete en la lista 
			// de jugadores. La lista de jugadores se borra antes de añadir los jugadores del fichero jugadores.txt
			void leeJugadores();
	};

#endif