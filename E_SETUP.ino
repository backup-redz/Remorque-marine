void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*if (!SD.begin(chipSelect)) {
    while (1) {
      Serial.println("Ecard failed, or not present$");
      delay(500);
    }
  }
  Serial.println("Ecard initialized.$");
  */
}
