/*
#define NOTE_C4  262  //DO
#define NOTE_CS4 277  //DO SOSTENIDO
#define NOTE_D4  294  //RE
#define NOTE_DS4 311  //RE SOSTENIDO
#define NOTE_E4  330  //MI
#define NOTE_F4  349  //FA
#define NOTE_FS4 370  //FA SOSTENIDO
#define NOTE_G4  392  //SOL
#define NOTE_GS4 415  //SOL SOSTENIDO
#define NOTE_A4  440  //LA
#define NOTE_AS4 466  //LA SOSTENIDO
#define NOTE_B4  494  //SI
*/


//  if (melody[thisNote] == 262 or melody[thisNote] == 349 or melody[thisNote] == 494)
//  if (melody[thisNote] == 294 or melody[thisNote] == 392)
//  if (melody[thisNote] == 330 or melody[thisNote] == 440)

int melody[] = {

NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4,
NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_F4,
NOTE_D4, NOTE_C4


};

// durations: 2 = half note, and 8/3,4,6,8,12. It appears that 8/2.9 is more accurate than 8/3.
float noteDurations[] = {

6,6,4,6,6,4,6,6,6,6,2,
6,6,6,6,6,6,6,6,6,6,6,
6,2

};
