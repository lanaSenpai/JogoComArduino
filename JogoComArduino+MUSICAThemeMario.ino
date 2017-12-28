#include <LiquidCrystal.h> 

LiquidCrystal lcd(9, 8, 5, 4, 3, 2); // Declarando os pinos a serem usados.
const int POTPIN = 1;  // Potenciometro no pino A1 do Arduino
//NOTAS DA MUSICA
/*************************************************
 * Public Constants
 *************************************************/
 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 3
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
 
 
// Precisamos girar todo o potenciometro para o carrinho subir e... 
//descer no visor do LCD.
int pino_x = A4; //Pino ligado ao VRX do joystick
int pino_y = A5; //Pino ligado ao VRY do joystick
int val_x;   //Armazena o valor do eixo VRX
int val_y;   //Armazena o valor do eixo VRY
int ledHIGH = 11;
const int MAXPOT = 1024; 

// Declara o pino digital 10 para acionar o Speaker.
const int SPEAKERPIN = 10;  
// Um pino analogico que não esta conectado a nada.
const int RANDSEEDPIN = 0; 

// Inicia devagar e a cada milisegundos vai aumetando a velocidade...
const int MINSTEPDURATION = 150; 

// Até chegar ao máximo de sua velocidade.
const int MAXSTEPDURATION = 300; 
const int NGLYPHS = 6;
byte glyphs[NGLYPHS][8] = {  // Iremos criar os carros e caminhões...

  // Imagem carro para cima.
  { B00000,
    B01110,
    B11111,
    B01010,
    B00000,
    B00000,
    B00000,
    B00000}

  // Imagem carro para baixo.
,  {B00000,
    B00000,
    B00000,
    B00000,
    B01110,
    B11111,
    B01010,
    B00000}

  // Imagem do caminhão para baixo.
,  {B00000,
    B00000,
    B00000,
    B00000,
    B11110,
    B11111,
    B01010,
    B00000}

  // Imagem de batida para baixo.
  ,{B00000,
    B00000,
    B00000,
    B10101,
    B01110,
    B01110,
    B10101,
    B00000}

};

const int NCARPOSITIONS = 4;

const char BLANK=32;

char car2glyphs[NCARPOSITIONS][2] = {

  {1,BLANK},{2,BLANK},{BLANK,1},{BLANK,2}

};

char truck2glyphs[NCARPOSITIONS][2] = {

  {3,BLANK},{4,BLANK},{BLANK,3},{BLANK,4}

};

char crash2glyphs[NCARPOSITIONS][2] = {

  {5,BLANK},{6,BLANK},{BLANK,5},{BLANK,6}

};

const int ROADLEN = 15; // Largura do LCD (sem contar nosso carro).

int road[ROADLEN]; // Posição dos outros carros.

char line_buff[2+ROADLEN]; 

int road_index;

int car_pos;

// Off-the-grid posição significa coluna vazia, então MAXROADPOS

 // Determina a probabilidade de um carro numa coluna

 // Por exemplo 3 * NCARPOSITIONS dá p = 1/3

const int MAXROADPOS = 3*NCARPOSITIONS;

int step_duration;

int crash; // Verdadeiro se haver colisão.

unsigned int crashtime;

const int CRASHSOUNDDURATION = 200;



const char *INTRO1="OlhePARAfrente";

const char *INTRO2="Tenha cuidado";

const int INTRODELAY = 2000; // Introdução com duração de dois segundos.

void setup()

{

  crash = crashtime = road_index = 0;

  step_duration = MAXSTEPDURATION;

  line_buff[1+ROADLEN] = '\0';

  randomSeed(analogRead(RANDSEEDPIN));

  for (int i=0; i<NGLYPHS; i++) {

    lcd.createChar(i+1,glyphs[i]);

  }

  for (int i=0; i<ROADLEN; i++) {

    road[i]=-1;

  }
  pinMode(7, OUTPUT);
  pinMode(SPEAKERPIN,OUTPUT);  // Define pino 10 com de saída.

  analogWrite(SPEAKERPIN,0); // Para estar no lado seguro.

  lcd.begin(16,2);  // Inicia o LCD de 16X2.

  getSteeringWheel();

  drawRoad();
  pinMode(ledHIGH,OUTPUT);
  digitalWrite(ledHIGH, HIGH);

  lcd.setCursor(1,0); // Na primeira coluna e linha 0...

  lcd.print(INTRO1);  // Imprima "CaminhoeAfrente".

  lcd.setCursor(1,1); // Na primeira coluna linha 1...

  lcd.print(INTRO2); // Imprima "Tenha cuidado".

  delay(INTRODELAY); // Aguarda 2 segundos antes de começar o jogo.

}

void loop() {
  sing(1);
  sing(1);
  sing(2);

  unsigned long now = millis()-INTRODELAY;

  if (!crash) {

    getSteeringWheel();

    crash = (car_pos==road[road_index]);

  }

  if (crash) {

    if (!crashtime) {

      crashtime=now;

      drawRoad();

      lcd.setCursor(2,0); // Na coluna 2 lina 0...

      lcd.print("Grave colisao!!"); // Imprima "Grave colisão!!".

      lcd.setCursor(2,1);

      lcd.print(now/1000);

      lcd.print(" segundos.");

    }

    if ((now-crashtime)<CRASHSOUNDDURATION) {

      analogWrite(SPEAKERPIN,random(255)); 

    } 

    else {

      analogWrite(SPEAKERPIN,0);  

    }

    delay(10); // De 10 milisegundos.

  } 

  else {

    int prev_pos = road[(road_index-1)%ROADLEN];

    int this_pos = random(MAXROADPOS);

    while (abs(this_pos-prev_pos)<1) { 

      this_pos = random(MAXROADPOS);

    }

    road[road_index] = this_pos;

    road_index = (road_index+1)%ROADLEN;

    drawRoad();

    delay(step_duration); // Delay de 300 milisegundos.
    
    if (step_duration>MINSTEPDURATION) {

      step_duration--; 

    }

  }
}
int song = 0;
 
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(melodyPin, underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
 
    }
 
  } else {
 
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];
 
      buzz(melodyPin, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
 
    }
  }
}
 
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
 
}
void getSteeringWheel() {
   car_pos = analogRead(pino_x);
  //Converte o valor lido para um valor entre 1 e 180 graus
  car_pos = map( car_pos,0,1024,180,NCARPOSITIONS);
car_pos = analogRead(pino_y);
car_pos = map( car_pos,0,1024,0,NCARPOSITIONS);
}

void drawRoad() {

  for (int i=0; i<2; i++) {

    if (crash) {

      line_buff[0]=crash2glyphs[car_pos][i];

    } 

     else {

      line_buff[0]=car2glyphs[car_pos][i];

    }

  for (int j=0; j<ROADLEN; j++) {

  int pos = road[(j+road_index)%ROADLEN];

  line_buff[j+1]= pos>=0&&pos>NCARPOSITIONS?truck2glyphs[pos][i]:BLANK;

    }

    lcd.setCursor(0,i);

    lcd.print(line_buff);

  }

}
 
