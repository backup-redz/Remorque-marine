void recep (char lettre) {
  Serial.print(lettre);
  delay(15);
  switch (lettre) {
    case 'E':
    {
      File dataFile = SD.open("data.txt", FILE_WRITE);
      char localCharac = '\0';
      char str[100];
      byte count = 0;
      while (commun.available() > 0 ) {
        localCharac = commun.read();
        str[count] = localCharac;
        count++;
        if (count == 98 || localCharac == '$') {
          break;
        }
        delay(15);
      }
      str[count] = '\0';
      String string1 = String(str);
      
      if (dataFile) {
        dataFile.println(string1);
        dataFile.close();
        commun.println("Einfos saved : $");
      }
    }
    break;

    case 'Q':
    {
      File dataFile = SD.open("data.txt", FILE_READ);
      Serial.println("on envoie Q sur le commun suivi de");
      commun.print("Q");
      delay(10);
      while (dataFile.available()) {
        delay(5);
        Serial.print(dataFile.peek());
        commun.write(dataFile.read());
      }
      dataFile.close();
      Serial.println("$");
      commun.print("$");
    }
    break;
    case 'T':
    {
      if (getTemperature(&temperatureInterieur, 2, true) != READ_OK) {
        Serial.println(F("Erreur de lecture du capteur"));
        return;
      }
      if (getTemperature(&temperatureExterieur, 3, true) != READ_OK) {
        Serial.println(F("Erreur de lecture du capteur"));
        return;
      }
      Serial.println(temperatureInterieur);
      Serial.println(temperatureExterieur);
    }
    break;
  }
}
