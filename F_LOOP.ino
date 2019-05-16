void loop() {
  // put your main code here, to run repeatedly:
  if (commun.available() > 0 ) {
    charac = commun.read();
    recep(charac);
  }
  if (Serial.available() > 0) {
    Serial.write(Serial.peek());
    commun.write(Serial.read());
  }
}
