#include "main.h"


// include pour la fonction getMacAddress
#include "help.h"



//---------------------------------------------
// *******  ESP-NOW ********

// includes nécessaires pour ESP-NOW
#include "com_esp_now.h"

// adresse MAC du récepteur : 3C:84:27:C0:F3:14
uint8_t broadcastAddress[] = {0x3C, 0x84, 0x27, 0xC0, 0xF3, 0x14};

// creation d'une instance de la structure
struct_message myData;

esp_now_peer_info_t peerInfo;
//----------------------------------------------




void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    // Initialisation de la communication série
    Serial.begin(115200);
    delay(10000);
    Serial.println("ESP-NOW Receiver");

    Serial.println("MAC address: " + getMacAddress());
    

    // Initialisation du WiFi en mode station
    WiFi.mode(WIFI_STA);
    //WiFi.disconnect();

    // Initialisation d'ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Enregistrement de la fonctoin de rappel pour l'envoi
    esp_now_register_send_cb(OnDataSent);

    // Ajout de l'ESP32 distant comme pair
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
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

    // envoi de données toutes les 10 secondes pour test
    static unsigned long lastTime = 0;
    if (millis() - lastTime > 10000)
    {
        lastTime = millis();
        // Préparation des données à envoyer
        strcpy(myData.a, "envoyé via ESP-NOW");
        myData.b = random(1,20);
        myData.c = 3.14;

        // état de la built-in LED
        myData.d = digitalRead(LED_BUILTIN) == HIGH ? true : false;

        // Envoi des données
        esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

        if (result == ESP_OK) {
            Serial.println("Sent with success");
        }
        else {
            Serial.println("Error sending the data");
        }
    }
    
}
