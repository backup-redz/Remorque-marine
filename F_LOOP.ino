void loop() {
  // put your main code here, to run repeatedly:
  if (commun.available() > 0 ) {
    charac = commun.read();
    recep(charac);
  }

  if (getTemperature(&temperatureInterieur, 2, true) != READ_OK) {
    //commun.println(F("Erreur de lecture du capteur"));
    return;
  }

   /* Lit la température ambiante à ~1Hz */
  if (getTemperature(&temperatureExterieur, 3, true) != READ_OK) {
    //commun.println(F("Erreur de lecture du capteur"));
    return;
  }
}
