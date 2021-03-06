#include <SD.h>
#include <SPI.h>
#include <OneWire.h>
#include <SoftwareSerial.h>

SoftwareSerial Blt (A5, A4);

const byte chipSelect = 4;
double positionsGPS[10];

float temperatureInterieur;
float temperatureExterieur;

enum DS18B20_RCODES {
  READ_OK,  // Lecture ok
  NO_SENSOR_FOUND,  // Pas de capteur
  INVALID_ADDRESS,  // Adresse reçue invalide
  INVALID_SENSOR  // Capteur invalide (pas un DS18B20)
};

// functions prototype
void recep (char lettre);
void recepBlt (char lettre); // bluetooth

void debug(String str);

byte getTemperature(float *temperature, byte pinTemp, byte reset_search);
