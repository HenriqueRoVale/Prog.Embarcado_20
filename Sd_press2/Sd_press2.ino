// Projeto para Criar / Ler Arquivos .txt junto ao Cartão SD Arduino
// Visite nossa loja através do link www.usinainfo.com.br
// Mais projetos em www.www.usinainfo.com.br/blog/</pre>
#include <SD.h>
#include <SPI.h>
#include "PressaoFreios.h"
TesteFreios P(A0);
 
File myFile;
 
int pinoSS = 10; // Pin 53 para Mega / Pin 10 para UNO
 
void setup() { // Executado uma vez quando ligado o Arduino
 
Serial.begin(9600); // Define BaundRate
pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída
 
if (SD.begin()) { // Inicializa o SD Card
Serial.println("SD Card pronto para uso."); // Imprime na tela
}
 
else {
Serial.println("Falha na inicialização do SD Card.");
return;
}

}
 
void loop() {

// Leitura da porta A5/Potenciometro
  int sensor = analogRead(A0);
  int valor = P.getPress();
  Serial.println(sensor);
  Serial.print("Pressao:");
  Serial.print(valor);
  Serial.println(" /bars");
 
myFile = SD.open("usina.txt", FILE_WRITE); // Cria / Abre arquivo .txt
 
if (myFile) { // Se o Arquivo abrir imprime:
Serial.println("Escrevendo no Arquivo .txt"); // Imprime na tela
myFile.print("PF1: "); // Escreve no Arquivo
myFile.println(valor);
myFile.println();
myFile.close(); // Fecha o Arquivo após escrever
Serial.println("Terminado."); // Imprime na tela
Serial.println(" ");
}
 
else {     // Se o Arquivo não abrir
Serial.println("Erro ao Abrir Arquivo .txt"); // Imprime na tela
}
 delay(2000);
}
