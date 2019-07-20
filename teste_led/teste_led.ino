//Controle Fita de Leds enderessáveis
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN        9 // Porta
#define NUMPIXELS 31 // Número de leds
#define DELAYVAL 1000// Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Controle Fita de Leds enderessáveis


int vermelho = 255;
int verde = 255;
int azul = 0;

void setup() {
  //Controle Fita de Leds enderessáveis  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  //Controle Fita de Leds enderessáveis

}

void loop() {

// error();
int numero = 8;
  defNum (numero, 1);
  defNum (numero, 2);
  defNum (numero, 3);
  defNum (numero, 4);

delay(DELAYVAL);

}

void defNum (int valor, int posicao){

    posicao = ((posicao - 1 ) * 7);
      
    pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 0));
    pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 0));
    pixels.show();
   
    switch (valor) {
      case 0: //{0, 1, 2, 3, 5, 6},     // 0
      
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
            break;
      case 1: // {6, 3},                 // 1
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 2: // {1, 2, 4, 5, 6},        // 2
            pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
          break;
      case 3: // {2, 3, 4, 5, 6},        // 3
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 4: //{0, 3, 4, 6},           // 4
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 5: //{0, 2, 3, 4, 5},        // 5
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 6: //{0, 1, 2, 4, 5},        // 6
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 7: //{3, 6, 5},              // 7
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 8: //{0, 1, 2, 3, 4, 5, 6},  // 8
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      case 9: //{0, 1, 2, 3, 4, 5}         // 9
            pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));
            pixels.show();
        break;
      default:
              error ();
        break;
    }
    pixels.setPixelColor(28, pixels.Color(vermelho, verde, azul));
    pixels.setPixelColor(29, pixels.Color(vermelho, verde, azul));
    pixels.show();
}


void error (){


   
    for (int j=0;j<3;j++) {
        
        int posicao = 0;
        pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde,azul ));
        
        posicao = 7;
        pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde,azul ));
    
        posicao = 14;
        pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde,azul ));
    
        posicao = 21;
        pixels.setPixelColor(0 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(1 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(2 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(3 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(4 + posicao, pixels.Color(vermelho, verde,azul ));
        pixels.setPixelColor(5 + posicao, pixels.Color(vermelho, verde, azul));
        pixels.setPixelColor(6 + posicao, pixels.Color(vermelho, verde, azul));

        pixels.setPixelColor(28, pixels.Color(vermelho, verde, azul));
        pixels.setPixelColor(29, pixels.Color(vermelho, verde, azul));
    
        pixels.show();
        delay(250);
        pixels.clear();
        pixels.show();
        delay(250);
    }
}
