void recep (char lettre) { // commun
  if (lettre == ' ') {
    return;
  }
  if (lettre != 'B') {
    debug(String(lettre));
  }
  
  delay(15);
  switch (lettre) {
    
    case 'T':
    {
      if (getTemperature(&temperatureInterieur, 2, true) != READ_OK) {
        debug(F("Erreur de lecture du capteur"));
        return;
      }
      if (getTemperature(&temperatureExterieur, 3, true) != READ_OK) {
        debug(F("Erreur de lecture du capteur"));
        return;
      }
      debug(String(temperatureInterieur, 5));
      debug(String(temperatureExterieur, 5));
    }
    break;
  
  case 'B':
    {
      while (true) {
        delay(10);
        char test = Serial.read();
        if (test == '$') {
          break;
        }
      }
    }
    break;
  }
}
