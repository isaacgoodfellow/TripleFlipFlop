//Show a light show to let us know it's on
void initSequence(){
  allHigh(200);
  allLow(100);
  allHigh(200);
  allLow(100);
}

void allHigh(int d){
  digitalWrite( f1.led_pin, HIGH );
  digitalWrite( f2.led_pin, HIGH );
  digitalWrite( f3.led_pin, HIGH );
  delay(d);
}

void allLow(int d){
  digitalWrite( f1.led_pin, LOW );
  digitalWrite( f2.led_pin, LOW );
  digitalWrite( f3.led_pin, LOW );
  delay(d);
}
