void recep (char lettre) {
  delay(15);
  switch (lettre) {
    case 'E':
    {
      File dataFile = SD.open("data.txt", FILE_WRITE);
      char localCharac = '\0';
      char str[100];
      byte count = 0;
      while (Serial.available() > 0 ) {
        localCharac = Serial.read();
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
        Serial.println("Einfos saved : $");
      }
    }
    break;

    case 'I':
    {
      File dataFile = SD.open("data.txt", FILE_READ);
      Serial.print("Electure de data.txt\n");
      while (dataFile.available()) {
        Serial.write(dataFile.read());
      }
      dataFile.close();
      Serial.print("$");
    }
    break;
  }
}
