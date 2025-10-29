// fichier com_esp_now.cpp
#include "com_esp_now.h"
#include <esp_now.h>
#include "main.h"


// fonction de rappel appelée lors de la réception des données
void OnDataReceived(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  struct_message myData;
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Int: ");
  Serial.println(myData.b);
  Serial.print("Float: ");
  Serial.println(myData.c);
  Serial.print("Bool: ");
  Serial.println(myData.d);

  // état de la LED en fonction de la valeur booléenne reçue
  if (myData.d) {
    digitalWrite(LED_BUILTIN, HIGH); // allume la LED
  } else {
    digitalWrite(LED_BUILTIN, LOW);  // éteint la LED
  }
}   
