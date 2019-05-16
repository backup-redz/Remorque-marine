void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Blt.begin(9600);
  Blt.print("slt noe");
  if (!SD.begin(chipSelect)) {
    while (1) {
      debug("card failed, or not present");
      if (!SD.begin(chipSelect)) {
        break;
      }
      delay(500);
    }
  }
  debug("card initialized.");
}
