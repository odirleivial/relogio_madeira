
//Controle Fita de Leds enderessáveis
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN        9 // Porta
#define NUMPIXELS 150 // Número de leds
#define DELAYVAL 1000// Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Controle Fita de Leds enderessáveis

void setup() {

//Controle Fita de Leds enderessáveis  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//Controle Fita de Leds enderessáveis
  
 // Serial(9600);
}

void loop() {

defNum (random(0,12), 0);
delay(DELAYVAL);
/*
    for (int i=0; i<10; i++){
      pixels.clear();
      pixels.show();
      delay(DELAYVAL);
     // pixels.setPixelColor(i, pixels.Color(random(0,200), random(0,200), random(0,200)));
      pixels.setPixelColor(i, pixels.Color(0, 0, 155));
      pixels.show();   // Send the updated pixel colors to the hardware
      delay(DELAYVAL);
    }
*/

}


void defNum (int valor, int posicao){
  pixels.clear();
  pixels.show();
  posicao = posicao -1;
  
  switch (valor) {
    case 0:
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(8 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
    
      break;
    case 1:
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 2:
          pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
        break;
    case 3:
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 4: //{1, 4, 6, 7},           // 4
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 5:
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 6: //{1, 2, 4, 5, 7},        // 6
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 7: //{3, 6, 7},              // 7
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 8: //{1, 2, 3, 4, 5, 6, 7},  // 8
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;
    case 9: //{1, 3, 4, 6, 7}         // 9
          pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 155));
          pixels.setPixelColor(7 + posicao, pixels.Color(0, 0, 155));
          pixels.show();
      break;

    default:
        for (int j=0;j<5;j++) {
          pixels.setPixelColor(1 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(2 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(3 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(4 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(5 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(6 + posicao, pixels.Color(155, 0, 0));
          pixels.setPixelColor(7 + posicao, pixels.Color(155, 0, 0));
          pixels.show();
          delay(250);
          pixels.clear();
          pixels.show();
          delay(250);
        }
      break;
  }
  
}
/*
void defNum (){

  int ledNum[10][7] = {
    {1, 2, 3, 5, 6, 7},     // 0
    {6, 7},                 // 1
    {2, 3, 4, 5, 6},        // 2
    {3, 4, 5, 6, 7},        // 3
    {1, 4, 6, 7},           // 4
    {1, 3, 4, 5, 7},        // 5
    {1, 2, 4, 5, 7},        // 6
    {3, 6, 7},              // 7
    {1, 2, 3, 4, 5, 6, 7},  // 8
    {1, 3, 4, 6, 7}         // 9
  };

  for (byte i = 0; i < 10; i++) {
    Serial.println(ledNum[i]);
  }
}
/*
1: 6 - 7
2: 2 - 3 - 4 - 5 - 6 
3: 3 - 4 - 5 - 6 - 7
4: 1 - 4 - 6 - 7
5: 1 - 3 - 4 - 5 - 7
6: 1 - 2 - 4 - 5 - 7
7: 3 - 6 - 7
8: 1 - 2 - 3 - 4 - 5 - 6 - 7
9: 1 - 3 - 4 - 6 - 7
0: 1 - 2 - 3 - 5 - 6 - 7
*/
