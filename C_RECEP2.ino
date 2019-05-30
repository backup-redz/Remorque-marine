void recepBlt (char lettre) { // bluetooth
  delay(10);
  switch (lettre) {
    case 'z':
    Serial.print('z');
    break;
    case 's':
    Serial.print('s');
    break;
    case 'q':
    Serial.print('q');
    break;
    case 'd':
    Serial.print('d');
    break;
    case 'K':
    Serial.print('K');
    break;
    case 'P':
    Serial.print('P');
    break;
    
    case 'E':
    {
      File dataFile = SD.open("data.txt", FILE_WRITE);
      char localCharac = '\0';
      char str[100];
      byte count = 0;
      while (Blt.available() > 0 ) {
        localCharac = Blt.read();
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
        Blt.println("Einfos saved : $");
      }
    }
    break;
    
    case 'Q':
    {
      File dataFile = SD.open("data.txt", FILE_READ);
      debug("on envoie Q sur le Blt suivi du fichier :");
      Blt.print("Q");
      delay(10);
      while (dataFile.available()) {
        delay(5);
        Blt.write(dataFile.read()); // on envoie le fichier sur le Blt
      }
      dataFile.close();
      Blt.print("$");
    }
    break;
    
    case 'G':
    {
      String cekejeresoi = "";
      char localCharac;
      while (Blt.available() > 0 ) {
        delay(8); // etre sur de recevoir le prochain char
        localCharac = Blt.read();
        if (localCharac == '$') {
          break;
        }
        cekejeresoi.concat(localCharac);
      }
      for (int i = 0; i < 5; i++) {
        positionsGPS[i*2] = getStringPartByNr(getStringPartByNr(cekejeresoi, ';', i), ',', 0).toDouble();
        positionsGPS[i*2+1] = getStringPartByNr(getStringPartByNr(cekejeresoi, ';', i), ',', 1).toDouble();

        String debugPos = "Lat : ";
        debugPos.concat(String(positionsGPS[i*2], 5));
        debugPos.concat("Long : ");
        debugPos.concat(String(positionsGPS[i*2+1], 5));
        debug(debugPos);
      }
    }
    break;
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

      Blt.print("interieur : ");
      Blt.print(String(temperatureInterieur, 5));
      Blt.print(", exterieur : ");
      Blt.print(String(temperatureExterieur, 5));
    }
    break;
    case '+':
    //On recoit ss ok 
      while (Blt.read() != 'K') {
        delay(10);
      }
      delay(10);
      Blt.read();
    break;
  }
}
