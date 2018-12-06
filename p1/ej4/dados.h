#ifndef DADOS_H
#define DADOS_H
	
	class Dados {
		private:
			int dado1_, dado2_; // guarda el valor actual de los dados
		public:
			//el constructor Dados() se ejecuta una sola vez y no devuelve nada
			// Inicializamos las variables privadas
			// la semilla se puede declarar en el constructor porque solo se declara una vez
			// inicializa un vector a 0 para despues guardar los 5 ultimos lanzamientos
			Dados();

			// void Dados::lanzamiento()
			// genera un valor aleatorio entre 1 y 6 para los dados
			// incremeta el contador que registra el numero de lanzamientos reslizados
			// añade el nuevo valor de los dados a la suma para calcular la media
			void lanzamiento();

			// int Dados::getDado1() - int Dados::getDado2()
			// deuelve el valor actual del dado			
			int getDado1();
			int getDado2();

			// bool Dados::setDado1(int dado) - bool Dados::setDado2(int dado)
			// comprueba que el valor recibido este entre 1 y 6
			// En caso afirmativo, lo establece como valor del dado
			// incremeta el contador que registra el numero de lanzamientos reslizados
			// añade el nuevo valor de los dados a la suma para calcular la media
			bool setDado1(int dado);
			bool setDado2(int dado);

			// int Dados::getSuma()
			// devuelve la suma del valor actual de los dados 1 y 2
			int getSuma();

			// int getDiferencia();
			// devuelve la diferencia entre el mayor y el menor de los valores de los dados
			int getDiferencia();
	};

#endif
