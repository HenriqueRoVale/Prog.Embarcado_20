#include "PressaoFreios.h"

TesteFreios::TesteFreios(int PIN) { //recebendo informações da biblioteca TesteFreios.h
  _PIN = PIN;
  pinMode (_PIN, INPUT);	//Inicio do sinal _PIN como INPUT
}

float TesteFreios::map(float x, float min, float max, float out_min, float out_max) {
	
	return (x - min) * (out_max - out_min) / (max - min) + out_min;
}
float TesteFreios::getPress(){
	float getPress = map((float)analogRead(_PIN), 65, 260, 0.0, 120.0);
	getPress = constrain(getPress, 0.0, 120.0);
		return getPress;
		
	}
	
int TesteFreios::getAnalog(){
	return analogRead(_PIN);
}
