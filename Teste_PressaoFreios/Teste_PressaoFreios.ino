#include "PressaoFreios.h"
TesteFreios P(A0);
void setup() {
 
  Serial.begin(115200);
//testesasjoijsaidj
}

void loop() {
  //int bar;
  //int sensor = analogRead(A0);
  //Serial.println(sensor);
  //sensor  = sensor*(5/1023);
  //bar = ((((sensor)/5)-0.1)*(1/0.01));
  //Serial.println(bar);
  
  Serial.print("Pressao:");
  Serial.print(P.getPress());
  Serial.println(" /bars");
  
  delay(2000);
} 
