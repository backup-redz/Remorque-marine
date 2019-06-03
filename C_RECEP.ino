void recep (char lettre) { // commun

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

    case '*':
      Blt.print("On est arrive");
      break;

    case 'B':
      {
        while (true) {
          delay(10);
          char test = Serial.read();
          Blt.write(test);
          if (test == '$') {
            break;
          }
        }
      }
      break;
  }
}
