#include <Arduino.h>
#include "com_esp_now.h"
#include "main.h"


//---------------------------------------------
// *******  ESP-NOW ********

// creation d'une instance de la structure
struct_message myData;

//----------------------------------------------




void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    // Initialisation de la communication série
    Serial.begin(115200);
    delay(1000);
    Serial.println("ESP-NOW Receiver");

    // Initialisation du WiFi en mode station
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    // Initialisation d'ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Enregistrement de la fonction de rappel pour la réception
    esp_now_register_recv_cb(OnDataReceived);

    Serial.println("ESP-NOW initialized");

    delay(1000);
    Serial.println("Setup done");
}

void loop()
{
    // Rien à faire ici, tout est géré par la fonction de rappel
    delay(5);
}
