
//Push check

#include<Time.h>
#include <LedControl.h> //  need the library

LedControl lc = LedControl(12, 11, 10, 1); //  pin 12: DataIn, pin 11: CLK, pin 10: LOAD

//Time code
#define TIME_HEADER "T"
#define TIME_REQUEST 7



void setup() {

  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 15); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  //Time code
  setSyncProvider(requestSync);
  Serial.println("Waiting for sync time");

}


long int lInt = 1234567890; //test int to parse to display

int epoch[10] = {(lInt % 10000000000) / 1000000000, (lInt % 1000000000) / 100000000, (lInt % 100000000) / 10000000, (lInt % 10000000) / 1000000,
                 (lInt % 1000000) / 100000, (lInt % 100000) / 10000, (lInt % 10000) / 1000, (lInt % 1000) / 100, (lInt % 100) / 10, lInt % 10,
                };



//number for first led matrix
byte zero[7] = {
  B11111000, B10001000, B10001000, B10001000, B11111000, B00000000, B00000000
}; //[highest row],[middle rows],[lowest row]
byte one[7] = {
  B01100000, B00100000, B00100000, B00100000, B01110000, B00000000, B00000000
};
byte two[7] = {
  B11111000, B00001000, B11111000, B10000000, B11111000, B00000000, B00000000
};
byte three[7] = {
  B11110000, B00001000, B11111000, B00001000, B11110000, B00000000, B00000000
};
byte four[7] = {
  B10001000, B10001000, B11111000, B00001000, B00001000, B00000000, B00000000
};
byte five[7] = {
  B11111000, B10000000, B11111000, B00001000, B11111000, B00000000, B00000000
};
byte six[7] = {
  B10000000, B10000000, B11111000, B10001000, B11111000, B00000000, B00000000
};
byte seven[7] = {
  B11111000, B10001000, B00001000, B00001000, B00001000, B00000000, B00000000
};
byte eight[7] = {
  B11111000, B10001000, B11111000, B10001000, B11111000, B00000000, B00000000
};
byte nine[7] = {
  B11111000, B10001000, B11111000, B00001000, B00001000, B00000000, B00000000
};








//number for second led matrix
byte zero2[7] = {
  B00000111, B00000100, B00000100, B00000100, B00000111, B10001000, B11111000
};
byte one2[7] = {
  B00000011, B00000001, B00000001, B00000001, B00000011, B10000000, B00000000
};
byte two2[7] = {
  B00000111, B00000000, B00000111, B00000100, B00000111, B10101000, B10111000
};
byte three2[7] = {
  B00000111, B00000000, B00000111, B00000000, B00000111, B10101000, B11111000
};
byte four2[7] = {
  B00000100, B00000100, B00000111, B00000000, B00000000, 00101000, B11111000
};
byte five2[7] = {
  B00000111, B00000100, B00000111, B00000000, B00000111, B10101000, B11101000
};
byte six2[7] = {
  B00000100, B00000100, B00000111, B00000100, B00000111, B10100000, B11100000
};
byte seven2[7] = {
  B00000111, B00000100, B00000000, B00000000, B00000000, B00001000, B11111000
};
byte eight2[7] = {
  B00000111, B00000100, B00000111, B00000100, B00000111, B10101000, B11111000
};
byte nine2[7] = {
  B00000111, B00000100, B00000111, B00000000, B00000000, B00101000, B11111000
};



byte show[7] = {
  zero[0] | five2[0], zero[1] | five2[1], zero[2] | five2[2], zero[3] | five2[3], zero[4] | five2[4], zero[5] | five2[5], zero[6] | five2[6]
};








byte tmpArray[7];
byte tmpArrayTwo[7];

void matrixOne(byte x[7]) {
  for (int i = 0; i < 7; i++) {
    tmpArray[i] = x[i];
  }

}

void matrixTwo(byte y[7]) {
  for (int i = 0; i < 7; i++) {
    tmpArrayTwo[i] = y[i];
  }

}


void getNumOne(int x) {

  if (x == 0) {
    matrixOne(zero);
  }
  else if (x == 1) {
    matrixOne(one);
  }
  else if (x == 2) {
    matrixOne(two);
  }
  else if (x == 3) {
    matrixOne(three);
  }
  else if (x == 4) {
    matrixOne(four);
  }
  else if (x == 5) {
    matrixOne(five);
  }
  else if (x == 6) {
    matrixOne(six);
  }
  else if (x == 7) {
    matrixOne(seven);
  }
  else if (x == 8) {
    matrixOne(eight);
  }
  else if (x == 9) {
    matrixOne(nine);
  }
  else if (x == NULL) {
    matrixOne(zero);
  }
}

void getNumTwo(int y) {

  if (y == 0) {
    matrixTwo(zero2);
  }
  else if (y == 1) {
    matrixTwo(one2);
  }
  else if (y == 2) {
    matrixTwo(two2);
  }
  else if (y == 3) {
    matrixTwo(three2);
  }
  else if (y == 4) {
    matrixTwo(four2);
  }
  else if (y == 5) {
    matrixTwo(five2);
  }
  else if (y == 6) {
    matrixTwo(six2);
  }
  else if (y == 7) {
    matrixTwo(seven2);
  }
  else if (y == 8) {
    matrixTwo(eight2);
  }
  else if (y == 9) {
    matrixTwo(nine2);
  }
}


void displayNum(byte x[7], byte y[7]) {
  lc.setRow(0, 0, x[6] | y[6]);
  lc.setRow(0, 1, x[5] | y[5]);
  lc.setRow(0, 2, x[4] | y[4]);
  lc.setRow(0, 3, x[3] | y[3]);
  lc.setRow(0, 4, x[2] | y[2]);
  lc.setRow(0, 5, x[1] | y[1]);
  lc.setRow(0, 6, x[0] | y[0]);
}



void displatEpochTime(long int eTime){ //Displays the epoch time on the 10 LED matrics

  long int lInt = eTime;

  int epoch[10] = {(lInt % 10000000000) / 1000000000, (lInt % 1000000000) / 100000000, (lInt % 100000000) / 10000000, (lInt % 10000000) / 1000000,
                 (lInt % 1000000) / 100000, (lInt % 100000) / 10000, (lInt % 10000) / 1000, (lInt % 1000) / 100, (lInt % 100) / 10, lInt % 10,
                };

  

  
}


//Time code
void digitalClockDisplay() {
  // digital clock display of the time
  Serial.println(static_cast<long int> (now()));
}

void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if ( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
      setTime(pctime); // Sync Arduino clock to the time received on the serial port
    }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);
  return 0; // the time will be sent later in response to serial mesg
}

void loop() {
  getNumOne(epoch[0]);
  getNumTwo(epoch[1]);
  displayNum(tmpArray, tmpArrayTwo);

  //displayShow();
  for (int x = 0; x < 7; x++) {
    Serial.println(epoch[x]);
  };

  delay(10000);
  //lc.setLed(0,2,2,true);


  //Time code
  if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus() != timeNotSet) {
    digitalClockDisplay();
  }


}

