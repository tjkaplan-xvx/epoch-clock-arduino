


#include <LedControl.h> //  need the library

LedControl lc = LedControl(12, 11, 10, 1); //  pin 12: DataIn, pin 11: CLK, pin 10: LOAD



void setup() {

  Serial.begin(9600);
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 15); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen



}


//*********LED MATRIX TESTING************//
long int lInt = 1234567890; //test int to parse to display

int epochTest[10] = {(lInt % 10000000000) / 1000000000, (lInt % 1000000000) / 100000000, (lInt % 100000000) / 10000000, (lInt % 10000000) / 1000000,
                     (lInt % 1000000) / 100000, (lInt % 100000) / 10000, (lInt % 10000) / 1000, (lInt % 1000) / 100, (lInt % 100) / 10, lInt % 10,
                    };
//********END LED MATRIX TESTING********//


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


void displayNum(int chipNum, byte x[7], byte y[7]) {
  lc.setRow(chipNum, 0, x[6] | y[6]);
  lc.setRow(chipNum, 1, x[5] | y[5]);
  lc.setRow(chipNum, 2, x[4] | y[4]);
  lc.setRow(chipNum, 3, x[3] | y[3]);
  lc.setRow(chipNum, 4, x[2] | y[2]);
  lc.setRow(chipNum, 5, x[1] | y[1]);
  lc.setRow(chipNum, 6, x[0] | y[0]);
}


//Displays the epoch time on the 10 LED matrics
void displayEpochTime(long int eTime) {

  long int lInt = eTime;

  int epoch[10] = {(lInt % 10000000000) / 1000000000, (lInt % 1000000000) / 100000000, (lInt % 100000000) / 10000000, (lInt % 10000000) / 1000000,
                   (lInt % 1000000) / 100000, (lInt % 100000) / 10000, (lInt % 10000) / 1000, (lInt % 1000) / 100, (lInt % 100) / 10, lInt % 10,
                  };

  for (int i = 0; i < 5; i++) {
    if (i = 0) {
      getNumOne(epoch[0]);
      getNumTwo(epoch[1]);
    }
    else if (i = 1) {
      getNumOne(epoch[2]);
      getNumTwo(epoch[3]);
    }
    else if (i = 2) {
      getNumOne(epoch[4]);
      getNumTwo(epoch[5]);
    }
    else if (i = 3) {
      getNumOne(epoch[6]);
      getNumTwo(epoch[7]);
    }
    else {
      getNumOne(epoch[8]);
      getNumTwo(epoch[9]);
    }
    displayNum(i, tmpArray, tmpArrayTwo);
  }
}


//Serial.println(static_cast<long int> (now()));


void loop() {

  displayEpochTime(lInt);
  
  getNumOne(epochTest[0]);
  getNumTwo(epochTest[1]);
  // displayNum(tmpArray, tmpArrayTwo);

  //displayShow();
  for (int x = 0; x < 7; x++) {
    Serial.println(epochTest[x]);
  };

  delay(10000);
  //lc.setLed(0,2,2,true);



}

