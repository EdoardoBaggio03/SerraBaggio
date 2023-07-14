
void apri() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(17, 14);
  display.print("APERTURA");
  display.setCursor(17, 38);
  display.print("FINESTRE");

  display.drawRect(0, 0, 128, 64,WHITE);
  display.display();
  digitalWrite(5, 0);
  delay(100);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  delay(100);
  digitalWrite(5, 1);
  aperto = true;

}
void chiudi() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(17, 14);
  display.print("CHIUSURA");
  display.setCursor(17, 38);
  display.print("FINESTRE");
  display.drawRect(0, 0, 128, 64,WHITE);
  display.display();
  digitalWrite(5, 0);
  delay(100);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  delay(100);
  digitalWrite(5, 1);
  aperto = false;

}

void ferma() {
  digitalWrite(5, 0);
}
