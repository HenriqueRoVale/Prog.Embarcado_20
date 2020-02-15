#include <math.h>
#include <arduino.h>

#define PIN 2
#define PI 3.1415926535897932384626433832795
int rps = 0;
float lastTime = 0.0f;

void setup() {
    //Declara o pino como input pullup, ou seja, quando o sensor não estiver mandando sinal, o pino ficara 5V
  pinMode(PIN, INPUT_PULLUP);
  //Define o pino como interrupção na função indutivo() na rampa de descida (de 5V para 0V)
  attachInterrupt(digitalPinToInterrupt(PIN), indutivo, FALLING);
  Serial.println("MArtins é um otario");
  //Inicializa a serial no baudrate de 115200
  Serial.begin(115200);  
}

void loop() {

  

}

void indutivo(){
    //Se o tempo atual menos o ultimo tempo registrador for maior que 1000 milisegundos
    if(millis() - lastTime > 1000){ 
        //Atribui o valor do ultimo tempo como o tempo atual
        lastTime = millis();
        //Printa a rotação por segundo
        int rpm;
        rpm = rps*60;
        Serial.print("RPM: "); Serial.println(rpm);
        int r = 22;
        int vm = rps*PI*r ;
        
        //Zera a rotações por segundo
        rps = 0;
    }
    else{ //Se Não\
        rps++; //Incrementa a rotação
        
    }
    
}
