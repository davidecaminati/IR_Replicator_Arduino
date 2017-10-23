/*
 * IR-replicator for Samsung TV
 *
 * This sketch helps blind people to set 
 * descriptive audio in a Samsung TV.
 * You need to download IRremote library to use this
 * and can use the IRrecvDump sketch in the examples
 * for find new code for your TV (or whatelse)
 *
 * This example code is in the public domain.
 *
 * Version 0.7
 * Created 28 Gen 2015 by  Davide Caminati
 *
 * http://caminatidavide.it/
 */

#include <IRremote.h>

const int SPEAKER_PIN = 9;
IRsend irsend;  // pin 3 PWM (hardcoded in the IRremote library )


// raw data for Samsung TV (if you have different TV, please look for DUMP the raw data of your actually remote control)
unsigned int GIU[68]={4500,4400,600,1600,600,1600,650,1600,600,500,600,500,650,500,
600,500,600,500,650,1600,600,1600,600,1650,600,500,600,500,650,500,600,500,600,500,
600,1650,600,500,600,500,600,550,600,500,600,1600,600,1650,600,500,600,500,650,1600,
600,1600,600,1600,650,1600,600,500,600,550,600,1600,600,};

unsigned int MENU[68]={4500,4400,600,1650,600,1600,600,1600,600,550,600,500,600,500,
600,550,600,500,600,1600,600,1650,600,1600,600,500,650,500,600,500,
600,500,650,500,600,500,600,1600,650,500,600,1600,600,1600,650,500,
600,500,600,500,650,1600,600,500,600,1600,650,500,600,500,600,1650,600,1600,600,1600,650,};

unsigned int ENTER[68]={4500,4400,600,1600,600,1650,600,1600,600,500,650,500,600,500,
600,500,600,550,600,1600,600,1600,650,1600,600,500,600,500,650,500,600,500,600,500,650,
500,600,500,600,500,650,1600,600,500,600,1600,650,1600,600,500,600,1650,600,1600,600,
1600,650,500,600,1600,600,500,650,500,600,1600,600,};


void setup()
{
  pinMode(SPEAKER_PIN,OUTPUT);
  delay(250);
  // start simulation IR remote
    bip();
    delay(100);
    // key sequence to send (1=MENU, 2=GIU, 3=ENTER)
    int sequence[] = {1, 2, 3, 2, 2, 2, 3, 2, 3, 1 }; 
    
    for (int i = 0; i < sizeof(sequence)/sizeof(int) ; i++){
      switch (sequence[i]){
      case 1:
    	  irsend.sendRaw(MENU,68,38);
      case 2:
    	  irsend.sendRaw(GIU,68,38);
      case 3:
    	   irsend.sendRaw(ENTER,68,38);
        } 
      delay(500);
      }   
    // end of simulation
    bip();
    bip();
    bip();
}


void loop() {
	// we dont need a loop
}

//sound feedback routine
void bip(){
  for (int i=50; i<100; i++) {
    analogWrite(SPEAKER_PIN,i);
  delay(10);
  }
  analogWrite(SPEAKER_PIN,0); // set mute
  delay(100);
}
  
