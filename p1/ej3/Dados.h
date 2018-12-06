#ifndef DADOS_H
#define DADOS_H
	
	class Dados {
		private:
			int dado1_, dado2_;
		public:
			Dados();

			void lanzamiento();
			
			int getDado1();
			int getDado2();

			bool setDado1(int dado);
			bool setDado2(int dado);

			int getSuma();
	};

#endif
