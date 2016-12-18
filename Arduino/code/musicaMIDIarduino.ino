
// PROYECTO "Tarjeta de Navidad v2" 
// LA IDEA ES HACER COMO EN LAS TARJETAS NAVIDEÑAS, CUANDO LAS ABRES SUENA MUSICA 
// Y PARPADEAN LAS LUCES AL SON DE LA MUSICA.

// POR CARLYMX carlymx@gmail.com

// ADAPTADO PARA LOS DIGISPARK ATTINY85.
// WEB OFFICIAL DIGISPARK: http://digistump.com/category/1
// Wiki DigiSpark: https://digistump.com/wiki/digispark/tutorials/connecting
// SE PUEDEN COMPRAR BARATOS EN: https://es.aliexpress.com/wholesale?catId=400103&initiative_id=AS_20161203125247&SearchText=digispark+attiny85

// BASADO EN EL TUTORIAL: https://www.arduino.cc/en/Tutorial/toneMelody


#include "pitches.h"            // BIBLIOTECA CON 7 OCTAVAS Y SU VALOR EN HERZIOS DE CADA NOTA MUSICAL. written by Brett Hagman.
#include "SongJimgleBells.h"    // AQUI SE INCLUYE LA CANCION A REPRODUCIR.

int sizeArray=sizeof(melody) / sizeof('NOTE_C4');     // CALCULAR EL TAMAÑO DE LA ARRAY DE LA MELODIA.

const int pulsador = 0;    // Pulsador PIN.
const int speaker = 1;     // Speaker PIN.
const int ledrojo = 2;     // Led Rojo PIN.
const int ledverde = 3;     // Led Verde PIN.
const int ledazul = 4;     // Led azul PIN.

int on1 = 0;
int fin = 0;

void setup() {

pinMode(speaker, OUTPUT);   // Speaker
pinMode(pulsador, INPUT);   // Pulsador 
pinMode(ledrojo, OUTPUT);   // Led Rojo
pinMode(ledverde, OUTPUT);  // Led Verde
pinMode(ledazul, OUTPUT);   // Led Azul
}

void loop() {
  int pulsa_estado=digitalRead(pulsador);

if (pulsa_estado == HIGH)
{
  if (on1 == 0) {on1 = 1;}
}

if (pulsa_estado == LOW and on1 == 1)
{
fin++;
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeArray; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    if (digitalRead(pulsador)==HIGH) {on1 = 0;}
    if (digitalRead(pulsador)==LOW and on1 == 0) {break;}
    if (fin > 3) { fin = 0; on1 = 0; break;}
    

    int noteDuration = 1500 / noteDurations[thisNote];
    tone(speaker, melody[thisNote], noteDuration);
    
        int pauseBetweenNotes = noteDuration * 1.30;
        if (melody[thisNote] == 262 or melody[thisNote] == 349 or melody[thisNote] == 494){    
        digitalWrite(ledrojo, HIGH);
        digitalWrite(ledverde, LOW);
        digitalWrite(ledazul, LOW);
        delay (pauseBetweenNotes-10);
        digitalWrite(ledrojo, LOW);
        digitalWrite(ledverde, LOW);
        digitalWrite(ledazul, LOW);
      }
      else if (melody[thisNote] == 294 or melody[thisNote] == 392){    
        digitalWrite(ledrojo, LOW);
        digitalWrite(ledverde, HIGH);
        digitalWrite(ledazul, LOW);
        delay (pauseBetweenNotes-10);
        digitalWrite(ledrojo, LOW);
        digitalWrite(ledverde, LOW);
        digitalWrite(ledazul, LOW);
      }
      else if (melody[thisNote] == 330 or melody[thisNote] == 440){    
        digitalWrite(ledrojo, LOW);
        digitalWrite(ledverde, LOW);
        digitalWrite(ledazul, HIGH);
        delay (pauseBetweenNotes-10);
        digitalWrite(ledrojo, LOW);
        digitalWrite(ledverde, LOW);
        digitalWrite(ledazul, LOW);
      }


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    if (digitalRead(pulsador)==HIGH) {on1 = 0;}
    if (digitalRead(pulsador)==LOW and on1 == 0) {break;}
    delay(pauseBetweenNotes/4);
    //delay(100);
    }  

    
       
}
    digitalWrite(ledrojo, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledazul, LOW);
     

}




























