#ifndef COM_ESP_NOW_H
#define COM_ESP_NOW_H
#include <esp_now.h>
#include <WiFi.h>

//---------------------------------------------
// ******* congiguration de ESP-NOW ********

// structure exemple des données envoyées
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;

void OnDataReceived(const uint8_t * mac, const uint8_t *incomingData, int len);
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

#endif

