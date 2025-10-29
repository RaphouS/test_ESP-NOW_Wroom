# Projet ESP-NOW pour ESP32

Ce projet est une implémentation de la communication ESP-NOW sur un ESP32 WROOM. ESP-NOW est un protocole de communication développé par Espressif qui permet une communication peer-to-peer entre les appareils ESP32/ESP8266.

## Description

Ce projet implémente un récepteur ESP-NOW qui peut recevoir des données structurées d'autres appareils ESP32. Il utilise la carte UPesy WROOM et est construit avec le framework Arduino dans PlatformIO.

## Caractéristiques

- Communication sans fil via ESP-NOW
- LED intégrée pour le retour visuel
- Communication série pour le débogage (115200 bauds)
- Structure de données personnalisée pour la transmission

## Structure des données

Le projet utilise une structure de données personnalisée pour la communication :

```cpp
struct struct_message {
    char a[32];    // Chaîne de caractères (32 bytes)
    int b;         // Entier
    float c;       // Nombre à virgule flottante
    bool d;        // Booléen
};
```

## Prérequis

- PlatformIO IDE
- ESP32 UPesy WROOM
- Framework Arduino

## Configuration

Le projet est configuré via le fichier `platformio.ini` avec les paramètres suivants :

```ini
[env:upesy_wroom]
platform = espressif32
board = upesy_wroom
framework = arduino
monitor_speed = 115200
```

## Structure du projet

```
├── platformio.ini          # Configuration PlatformIO
├── src/
│   ├── main.cpp           # Code principal
│   ├── main.h            # En-tête principal
│   ├── com_esp_now.cpp   # Implémentation ESP-NOW
│   └── com_esp_now.h     # En-tête ESP-NOW
├── include/               # Headers additionnels
└── lib/                  # Bibliothèques
```

## Installation

1. Clonez ce dépôt
2. Ouvrez le projet dans PlatformIO
3. Connectez votre ESP32
4. Compilez et téléversez le code

## Utilisation

1. Le dispositif démarre en mode récepteur ESP-NOW
2. La LED intégrée peut être utilisée pour le retour d'état
3. Les messages reçus peuvent être visualisés via le moniteur série (115200 bauds)

## Licence

Ce projet est sous licence libre.

## Contribution

Les contributions sont les bienvenues. N'hésitez pas à ouvrir une issue ou à proposer une pull request.