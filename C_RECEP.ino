void recep (char lettre) {
  Serial.println("On recoit");
  Serial.println(lettre);
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
      commun.print("Q");
      delay(10);
      while (dataFile.available()) {
        delay(5);
        commun.write(dataFile.read());
      }
      dataFile.close();
      commun.print("$");
    }
    break;
  }
}
