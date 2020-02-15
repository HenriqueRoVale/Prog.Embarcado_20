#ifndef PRESSAOFREIOS_H	//Verificar a existencia de outra biblioteca com esse nome
#define PRESSAOFREIOS_H	//Definir o nome da biblioteca como "PressaoFreios"
#include "Arduino.h" //Incluir biblioteca do arduino para ser ultilizada
#include "math.h"

class TesteFreios{
	
  private: 
    int _PIN;	//Objeto criado (Sensor de Pressao de Freios)
	float map(float x, float min, float max, float out_min, float out_max);

  public:
	TesteFreios();	//Criação do objeto
	TesteFreios(int);	//Criação do objeto com parametros
    
	float getPress(); //Função para calcular a pressao 
	int getAnalog();
};
#endif