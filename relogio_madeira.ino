//Controle Fita de Leds enderessáveis
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        3  // Novo: 6 - antigo: 3
#define NUMPIXELS 31  // Número de leds
#define DELAYVAL 250  // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Controle Fita de Leds enderessáveis

//Definições Relógio 
#include "Wire.h"
#define DS1307_ADDRESS 0x68
byte zero = 0x00; 
//Definições Relógio 

// Definição das portas dos botões de ajuste de hora e cor
#define BT_HORA A1    // Novo: 2 - antigo: A1
#define BT_MINUTO A0  // Novo: 3 - antigo: A0
#define BT_COR A2     // Novo: 4 - antigo: A2

String horaAterior = "";

// definições das variáveis para ajuste de cor
int vermelho = 255;
int verde = 0;
int azul = 0;
int vCor = 0;

void setup() {
  //Controle Fita de Leds enderessáveis  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  //Controle Fita de Leds enderessáveis
    
  Serial.begin(9600);
  Wire.begin();

  // Definição dos botões de ajuste de hora e cor
  pinMode(BT_HORA, INPUT);
  pinMode(BT_MINUTO, INPUT);
  pinMode(BT_COR, INPUT);

  //ajusteHora(18,10);
  
}

void loop() {

  // Verifica se houve alteração na hora e manda exibir o novo valor
  String horaAtual = Mostrarelogio();
  if (horaAterior != horaAtual){
      
      //Verifica se está no modo de cor randomica
      if (vCor == 7){
        exibeHoraCor();}
      else {
        exibeHora();
      }

    horaAterior = horaAtual;
  }

  // Inicio - Leitura dos botões de ajuste de hora e cor
  int stBtHora = digitalRead(BT_HORA);
  int stBtMin = digitalRead(BT_MINUTO);
  int stBtCor = digitalRead(BT_COR);

    if (stBtHora == HIGH && stBtMin == LOW) {    //Ajusta a hora
          int hora = horaAtual.substring(0, 2).toInt();
          int minuto = horaAtual.substring(2, 4).toInt();
          ajusteHora(hora + 1, minuto );

          Serial.println("HORA");

    }

    if (stBtMin == HIGH && stBtHora == LOW) {    //Ajusta o minuto
          int hora = horaAtual.substring(0, 2).toInt();
          int minuto = horaAtual.substring(2, 4).toInt();
          if (minuto >= 59){
            minuto = -1;
          }
          ajusteHora(hora, minuto + 1 );
          Serial.println("MINUTO");

    }

        if (stBtMin == HIGH && stBtHora == HIGH) {    //Entra em modo manutenção

          defNum (8, 1, vermelho, verde, azul);
          defNum (8, 2, vermelho, verde, azul);
          defNum (8, 3, vermelho, verde, azul);
          defNum (8, 4, vermelho, verde, azul);

          Serial.println("Modo Manutenção");

    }

    if (stBtCor == HIGH) {   //Ajusta a Cor
      vermelho, verde, azul = muda_cor();

      if (vCor == 7){
        exibeHoraCor();}
      else {
        exibeHora();
      }

    }
   // Fim - Leitura dos botões de ajuste de hora e cor   

   delay(DELAYVAL);
}

int muda_cor(){ //Função para ajuste de cor
  // Essa função ler o valor da variável vCor para definir os valores das variáveis de cor, 
  // a cada leitura a variável vCor é incrementada para que na proxima chamada uma nova cor seja selecionada
  
  vCor++;

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
    case 6:
        vermelho = 255;
        verde = 255;
        azul = 255;
        Serial.println("BRANCO");
    break;  
      case 7:
          exibeHoraCor();
          Serial.println("Arco-iro");
    break;    
    default:
        vCor = 0;
    break;  
    }

    return vermelho, verde, azul;
}

void exibeHora(){ //Função para exibir a hora no display de led

  String horaAtual = Mostrarelogio();

  defNum (horaAtual.substring(0, 1).toInt(), 1, vermelho, verde, azul);
  defNum (horaAtual.substring(1, 2).toInt(), 2, vermelho, verde, azul);
  defNum (horaAtual.substring(2, 3).toInt(), 3, vermelho, verde, azul);
  defNum (horaAtual.substring(3, 4).toInt(), 4, vermelho, verde, azul);

}

void exibeHoraCor(){ //Função para exibir a hora no display de led com cores randomicas em cada caractere

  String horaAtual = Mostrarelogio();
 
  vCor = random(0, 7);
  muda_cor();
  defNum (horaAtual.substring(0, 1).toInt(), 1, vermelho, verde, azul);
   
  vCor = random(0, 7);
  muda_cor();
  defNum (horaAtual.substring(1, 2).toInt(), 2, vermelho, verde, azul);
  
  vCor = random(0, 7);
  muda_cor();
  defNum (horaAtual.substring(2, 3).toInt(), 3, vermelho, verde, azul);
  
  vCor = random(0, 7);
  muda_cor();
  defNum (horaAtual.substring(3, 4).toInt(), 4, vermelho, verde, azul);

  //Pontos
  vCor = random(0, 7);
  muda_cor();
  pixels.setPixelColor(28, pixels.Color(vermelho, verde, azul));
  pixels.setPixelColor(29, pixels.Color(vermelho, verde, azul));
  pixels.show();

  vCor = 7;

}

void defNum (int valor, int posicao, int cVermelho, int cVerde, int cAzul){ 
// Função para excrever os números de 0 a 9 no display
// recebe o valor a ser impresso, a posição no display e as três variáveis de vCor

    posicao = ((posicao - 1 ) * 7);
    
    switch (valor) {
      case 0: //{0, 1, 2, 3, 5, 6},     // 0

            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(1 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            
            // apaga os leds não utilizado no número
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
            break;
      case 1: // {6, 3},                 // 1
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      case 2: // {1, 2, 4, 5, 6},        // 2
            pixels.setPixelColor(1 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 0));


            pixels.show();
          break;
      case 3: // {2, 3, 4, 5, 6},        // 3
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));


            pixels.show();
        break;
      case 4: //{0, 3, 4, 6},           // 4
            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      case 5: //{0, 2, 3, 4, 5},        // 5
            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      case 6: //{0, 1, 2, 4, 5},        // 6
            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(1 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      case 7: //{3, 6, 5},              // 7
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      case 8: //{0, 1, 2, 3, 4, 5, 6},  // 8
            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(1 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.show();
        break;
      case 9: //{0, 1, 2, 3, 4, 5}         // 9
            pixels.setPixelColor(0 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(2 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(3 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(4 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(5 + posicao, pixels.Color(cVermelho, cVerde, cAzul));
            pixels.setPixelColor(6 + posicao, pixels.Color(cVermelho, cVerde, cAzul));

            // apaga os leds não utilizado no número
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));

            pixels.show();
        break;
      default:
            pixels.setPixelColor(0 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(1 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(2 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(3 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(4 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(5 + posicao, pixels.Color(0, 0, 0));
            pixels.setPixelColor(6 + posicao, pixels.Color(0, 0, 0));
            pixels.show();
        break;
    }
      pixels.setPixelColor(28, pixels.Color(cVermelho, cVerde, cAzul));
      pixels.setPixelColor(29, pixels.Color(cVermelho, cVerde, cAzul));
      pixels.show();
}

void ajusteHora(byte horas, byte minutos)   //Seta a data e a hora do DS1307
{
  byte segundos = 0; //Valores de 0 a 59
  //byte minutos = 18; //Valores de 0 a 59
  //byte horas = 14; //Valores de 0 a 23
  byte diadasemana = 0; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 2; //Valores de 1 a 31
  byte mes = 4; //Valores de 1 a 12
  byte ano = 83; //Valores de 0 a 99
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

String Mostrarelogio() //Função para retornar a hora no formato HH12MI
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
 
  if(horas == 0){
    horas = 12;
  } 

  //adiciona zero a esquera
  String strHora = "";
  if(horas < 10){
   strHora = "0" + String(horas);
  }else{
   strHora = horas;
  }
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
  
  horaAtual = strHora + strMinuto;

        Serial.print("horaAtual: ");
        Serial.println(horaAtual);
  return horaAtual;
}
