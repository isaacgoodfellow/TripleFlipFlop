typedef struct flip{
  uint8_t led_pin;
  uint8_t gate_pin;
  uint8_t input_pin;
  boolean state;
  boolean last_read;
};

struct flip f1, f2, f3;

void setup(){
  
  f1.led_pin = 9;
  f1.gate_pin= 8;
  f1.input_pin= 2;
  f1.state = false;
  f1.last_read = false;
  
  f2.led_pin = 10;
  f2.gate_pin= 7;
  f2.input_pin= 1;
  f2.state = false;
  f2.last_read = false;
  
  f3.led_pin = 11;
  f3.gate_pin= 6;
  f3.input_pin= 0;
  f3.state = false;
  f3.last_read = false;
  
  pinMode( f1.led_pin, OUTPUT );
  pinMode( f1.gate_pin, OUTPUT );
  pinMode( f1.input_pin, INPUT );

  pinMode( f2.led_pin, OUTPUT );
  pinMode( f2.gate_pin, OUTPUT );
  pinMode( f2.input_pin, INPUT );

  pinMode( f3.led_pin, OUTPUT );
  pinMode( f3.gate_pin, OUTPUT );
  pinMode( f3.input_pin, INPUT );
  
  initSequence();
 
}

void loop(){
  
 doFlop(&f1); 
 doFlop(&f2); 
 doFlop(&f3); 

}

//run the flip flop
void doFlop(struct flip* flop){
  boolean pin_state = digitalRead(flop->input_pin);
  if(pin_state != flop->last_read && pin_state){
    flop->state = !flop->state;
    digitalWrite( flop->led_pin , flop->state );
    digitalWrite( flop->gate_pin , flop->state );
  }
  flop->last_read = pin_state;
}


