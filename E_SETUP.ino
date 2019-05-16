void setup() {
  // put your setup code here, to run once:
  commun.begin(9600);
  Serial.begin(9600);
  if (!SD.begin(chipSelect)) {
    while (1) {
      //commun.println("Ecard failed, or not present$");
      delay(500);
    }
  }
  //commun.println("Ecard initialized.$");
}
