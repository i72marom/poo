#ifndef DADOS_H
#define DADOS_H
	
	class Dados {
		private:
			int dado1_, dado2_; // guarda el valor actual de los dados
			int cont1_, cont2_; // guarda el numero actual de lanzamientos
			float sum1_, sum2_; // valor de la suma de todos los dados lanzados hasta el mometo
			int v1_[5], v2_[5]; // almacena el valor de los ultimos 5 dados lanzados
			
			// void rellenaVector1() - void rellenaVector2()
			// guarda el ultimo valor de los dados en el vector
			void rellenaVector1();
			void rellenaVector2();
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

			// int Dados::getLanzamientos1() - int Dados::getLanzamientos2()
			// devuelve el numero actual de lanzamientos
			int getLanzamientos1();
			int getLanzamientos2();

			// float Dados::getMedia1() - float Dados::getMedia2()
			// devuelve el valor actual de la media
			float getMedia1();
			float getMedia2();

			// void getUltimos1(int *v) - void getUltimos2(int *v)
			// recibe un vector de 5 enteros y guarda en el los valores de los
			// 5 ultimos lanzamientos
			void getUltimos1(int *v);
			void getUltimos2(int *v);
	};

#endif
