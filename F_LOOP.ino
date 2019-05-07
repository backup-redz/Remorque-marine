void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0 ) {
    charac = Serial.read();
    recep(charac);
  }

  if (getTemperature(&temperatureInterieur, 2, true) != READ_OK) {
    Serial.println(F("Erreur de lecture du capteur"));
    return;
  }

  /* Affiche la température */
  Serial.print(F("Temperature 1 : "));
  Serial.print(temperatureInterieur, 2);
  Serial.write(176); // Caractère degré
  Serial.write('C');
  Serial.println();

   /* Lit la température ambiante à ~1Hz */
  if (getTemperature(&temperatureExterieur, 3, true) != READ_OK) {
    Serial.println(F("Erreur de lecture du capteur"));
    return;
  }
  /* Affiche la température */
  Serial.print(F("Temperature 2 : "));
  Serial.print(temperatureExterieur, 2);
  Serial.write(176); // Caractère degré
  Serial.write('C');
  Serial.println();
}
