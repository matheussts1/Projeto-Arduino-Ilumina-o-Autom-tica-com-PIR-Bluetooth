void loop() {
  if (BT.available()) {
    String comando = BT.readString();
    comando.trim();

    if (comando == "1") {
      sistemaLigado = true;
      BT.println("Sistema LIGADO");
      Serial.println("Sistema LIGADO");
    }

    if (comando == "0") {
      sistemaLigado = false;
      analogWrite(TRANSISTOR_PIN, 0);
      BT.println("Sistema DESLIGADO");
      Serial.println("Sistema DESLIGADO");
    }
  }

  if (!sistemaLigado) return;

  int leitura = digitalRead(SENSOR_PIR);

  if (leitura == HIGH) {
    delay(80);
    if (digitalRead(SENSOR_PIR) == HIGH) {
      analogWrite(TRANSISTOR_PIN, 255);
      ultimoMovimento = millis();
    }
  }

  if (millis() - ultimoMovimento > 1000) {
    analogWrite(TRANSISTOR_PIN, 0);
  }

  delay(40);
}
