
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

//Definições Relógio 
#include "Wire.h"
#define DS1307_ADDRESS 0x68
byte zero = 0x00; 
//Definições Relógio 

String horaAterior = "";

void setup() {
  //Controle Fita de Leds enderessáveis  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  //Controle Fita de Leds enderessáveis
    
  Serial.begin(9600);

  Wire.begin();
  Serial.begin(9600);
  
  //A linha abaixo pode ser retirada apos setar a data e hora
  // SelecionaDataeHora(); 
  
}

void loop() {

//defNum (2, 1);
//defNum (2, 2);
//defNum (8, 3);
//defNum (8, 4);

String horaAtual = Mostrarelogio();
if (horaAterior != horaAtual){
  horaAterior = horaAtual;

  defNum (horaAtual.substring(0, 1).toInt(), 1);
  defNum (horaAtual.substring(1, 2).toInt(), 2);
  defNum (horaAtual.substring(2, 3).toInt(), 3);
  defNum (horaAtual.substring(3, 4).toInt(), 4);
}

delay(DELAYVAL);

Mostrarelogio();

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
      
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
            break;
      case 1: // {6, 3},                 // 1
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 2: // {1, 2, 4, 5, 6},        // 2
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
          break;
      case 3: // {2, 3, 4, 5, 6},        // 3
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 4: //{0, 3, 4, 6},           // 4
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 5: //{0, 2, 3, 4, 5},        // 5
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 6: //{0, 1, 2, 4, 5},        // 6
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 7: //{3, 6, 5},              // 7
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 8: //{0, 1, 2, 3, 4, 5, 6},  // 8
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      case 9: //{0, 1, 2, 3, 4, 5}         // 9
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 250));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 250));
            pixels.show();
        break;
      default:
              error ();
        break;
    }
}

void error (){
   
    for (int j=0;j<3;j++) {
        
        int posicao = 0;
        pixels.setPixelColor(0 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(1 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(2 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(3 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(4 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(5 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(6 + posicao, pixels.Color(250, 0, 0));
        
        posicao = 7;
        pixels.setPixelColor(0 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(1 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(2 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(3 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(4 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(5 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(6 + posicao, pixels.Color(250, 0, 0));
    
        posicao = 14;
        pixels.setPixelColor(0 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(1 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(2 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(3 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(4 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(5 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(6 + posicao, pixels.Color(250, 0, 0));
    
        posicao = 21;
        pixels.setPixelColor(0 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(1 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(2 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(3 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(4 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(5 + posicao, pixels.Color(250, 0, 0));
        pixels.setPixelColor(6 + posicao, pixels.Color(250, 0, 0));
        pixels.show();
        delay(250);
        pixels.clear();
        pixels.show();
        delay(250);
    }
}

void SelecionaDataeHora()   //Seta a data e a hora do DS1307
{
  byte segundos = 10; //Valores de 0 a 59
  byte minutos = 14; //Valores de 0 a 59
  byte horas = 20; //Valores de 0 a 23
  byte diadasemana = 0; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 14; //Valores de 1 a 31
  byte mes = 7; //Valores de 1 a 12
  byte ano = 19; //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero); //Start no CI
  Wire.endTransmission(); 
}


byte ConverteParaBCD(byte val){ //Converte o número de decimal para BCD
  return ( (val/10*16) + (val%10) );
}

byte ConverteparaDecimal(byte val)  { //Converte de BCD para decimal
  return ( (val/16*10) + (val%16) );
}

String Mostrarelogio()
{
  String horaAtual = "";
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111); 

  //ajusta a hora para forto até 12hs
  if(horas > 12){
    horas = horas - 12;
  } 

  //adiciona zero a esquera
  String strHora = "";
  if(horas < 10){
   strHora = "0" + String(horas);
  }else{
   strHora = horas;

  //adiciona zero a esquera
  String strMinuto = "";
  if(minutos < 10){
   strMinuto = "0" + String(minutos);
  }else{
   strMinuto = minutos;
  }

  //adiciona zero a esquera
  String strSegundos = "";
  if(segundos < 10){
   strSegundos = "0" + String(segundos);
  }else{
   strSegundos = segundos;

  }

  Serial.print("Hora : ");
  Serial.print(horas);
  Serial.print(":");
  Serial.print(minutos);
  Serial.print(":");
  Serial.println(segundos);

  //exibe hora no monitor serial
  horaAtual = strHora + strMinuto + strSegundos;
  Serial.println(horaAtual);

  return horaAtual;
}
