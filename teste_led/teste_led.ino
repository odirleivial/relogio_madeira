//Controle Fita de Leds enderessáveis
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN        6 // Porta
#define NUMPIXELS 31 // Número de leds
#define DELAYVAL 2000// Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Controle Fita de Leds enderessáveis


int vermelho = 49;
int   = 206;
int azul = 190;
int vCor = 0;

void setup() {
  //Controle Fita de Leds enderessáveis  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  //Controle Fita de Leds enderessáveis

  Serial.begin(9600);
  Serial.println("TESTE Fita LED Enderessável");

}

void loop() {

// error();
  int numero = random(0,10);
  // int numero = 8;
  defNum (numero, 1);
  defNum (numero, 2);
  defNum (numero, 3);
  defNum (numero, 4);

  vCor = random(0,7);
  muda_cor();

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

int muda_cor(){ //Função para ajuste de cor
  // Essa função ler o valor da variável vCor para definir os valores das variáveis de cor, 
  // a cada leitura a variável vCor é incrementada para que na proxima chamada uma nova cor seja selecionada

  switch (vCor) {
    case 0:
      vermelho = 0;
      verde = 0;
      azul = 255;
      Serial.println("Azul");
    break;
    case 1:
        vermelho = 255;
        verde = 0;
        azul = 0;
        Serial.println("VERMELHO");
    break; 
    case 2:
        vermelho = 0;
        verde = 255;
        azul = 0;
        Serial.println("VERDE");
    break; 
    case 3:
        vermelho = 14;
        verde = 222;
        azul = 217;
        Serial.println("CIANO");
    break;   
    case 4:
        vermelho = 255;
        verde = 0;
        azul = 255;
        Serial.println("ROSA");
    break;  
    case 5:
        vermelho = 255;
        verde = 230;
        azul = 0;
        Serial.println("AMARELO");
    break; 
    default:
        vermelho = 255;
        verde = 255;
        azul = 255;
        Serial.println("BRANCO");
        vCor = 0;
    break;  
    }
    vCor++;

    return vermelho, verde, azul;
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
