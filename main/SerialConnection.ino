String readStringSerial() {  
  String conteudo = "";
  
  // check if data is available
  if (Serial.available() > 0) {
    // read the incoming string:
    delay(50);
    conteudo = Serial.readStringUntil('\n');
  }
    
  return conteudo;
}
