#include <FastLED.h>

#define MATRIX_WIDTH 10
#define MATRIX_HEIGHT 10
#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)
#define DATA_PIN 21

CRGB leds[NUM_LEDS];

int ledLayout[MATRIX_HEIGHT][MATRIX_WIDTH] = {
  {91, 90, 71, 70, 51, 50, 31, 30, 11, 10},
  {92, 89, 72, 69, 52, 49, 32, 29, 12, 9},
  {93, 88, 73, 68, 53, 48, 33, 28, 13, 8},
  {94, 87, 74, 67, 54, 47, 34, 27, 14, 7},
  {95, 86, 75, 66, 55, 46, 35, 26, 15, 6},
  {96, 85, 76, 65, 56, 45, 36, 25, 16, 5},
  {97, 84, 77, 64, 57, 44, 37, 24, 17, 4},
  {98, 83, 78, 63, 58, 43, 38, 23, 18, 3},
  {99, 82, 79, 62, 59, 42, 39, 22, 19, 2},
  {100, 81, 80, 61, 60, 41, 40, 21, 20, 1}
};

const char letterA[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterB[][3] = {
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 0}
};

const char letterC[][3] = {
  {0, 1, 1},
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {0, 1, 1},
  {0, 1, 1}
};

const char letterD[][3] = {
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 0}
};

const char letterE[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterF[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0}
};

const char letterG[][3] = {
  {0, 1, 1},
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {0, 1, 1},
  {0, 1, 1}
};

const char letterH[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterI[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterJ[][3] = {
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterK[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterL[][3] = {
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterM[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterN[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterO[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterP[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 0, 0}
};

const char letterQ[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 0, 1}
};

const char letterR[][3] = {
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterS[][3] = {
  {0, 1, 1},
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 0},
  {1, 1, 0},
  {0, 0, 1},
  {0, 0, 1},
  {1, 1, 0},
  {1, 1, 0}
};

const char letterT[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0}
};

const char letterU[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterV[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {0, 1, 0},
  {0, 1, 0}
};

const char letterW[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterX[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {0, 1, 0},
  {0, 1, 0},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1}
};

const char letterY[][3] = {
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 0, 1},
  {1, 1, 1},
  {1, 1, 1},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0},
  {0, 1, 0}
};

const char letterZ[][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {0, 0, 1},
  {0, 0, 1},
  {0, 1, 0},
  {0, 1, 0},
  {1, 0, 0},
  {1, 0, 0},
  {1, 1, 1},
  {1, 1, 1}
};

const char letterSpace[][1] = {
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0}
};


void displayLetter(const char letter[10][3], CRGB color , int index) {
  // Clear the display
  

  // Display the letter
  for (int row = 0; row < MATRIX_HEIGHT; row++) {
    for (int col = 0; col < 3;col++) {

        if(col+index >=0 && (col+index) < MATRIX_WIDTH ){
          int ledIndex = ledLayout[row][col+index];
            leds[ledIndex-1] = (letter[row][col] == 1) ? color : CRGB::Black;
        }

      
  
    }
  }

  FastLED.show();
  delay(10); // Adjust the delay based on your desired display time
}


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


const char (*convertChar(char c))[3]{
  switch (c) {
    case 'A': return letterA;
    case 'B': return letterB;
    case 'C': return letterC;
    case 'D': return letterD;
    case 'E': return letterE;
    case 'F': return letterF;
    case 'G': return letterG;
    case 'H': return letterH;
    case 'I': return letterI;
    case 'J': return letterJ;
    case 'K': return letterK;
    case 'L': return letterL;
    case 'M': return letterM;
    case 'N': return letterN;
    case 'O': return letterO;
    case 'P': return letterP;
    case 'Q': return letterQ;
    case 'R': return letterR;
    case 'S': return letterS;
    case 'T': return letterT;
    case 'U': return letterU;
    case 'V': return letterV;
    case 'W': return letterW;
    case 'X': return letterX;
    case 'Y': return letterY;
    case 'Z': return letterZ;

    default: return nullptr; // Default case if character is not found
  }
}



void displaySentence( String sentence){

  CRGB color(0,0,255);
  int offset = MATRIX_WIDTH - 1 ;
   fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
   while (true) {
   for (int i = 0; i < sentence.length()  ; i++) {
    
    if(i%2 == 0){
      color=CRGB(0,0,255);
    }else{
      color=CRGB(0,255,0);
    }


    
    

    if(i==sentence.length()-1){
      if(i*3 + offset <= -3){
        offset = MATRIX_WIDTH - 1 ;
      }
    }
    
  
    if(sentence[i]==' '){
      
    }else{
      displayLetter(convertChar(sentence[i]), color,i*3 + offset);
    }
    
   }
   offset -= 1 ;
   }
  
}



void loop() {
  // Example: Slide the text "HELLO" from right to left
  //slideText("HELLO", CRGB::Blue);

 displaySentence("AEROBOTIX INSAT");
  
//  displayLetter(letterA, CRGB(255,0,0));
//  displayLetter(letterB, CRGB(255,0,0));
//  displayLetter(letterC, CRGB(255,0,0));
//  displayLetter(letterD, CRGB(255,0,0));
//  displayLetter(letterE, CRGB(255,0,0));
//  displayLetter(letterF, CRGB(255,0,0));
//  displayLetter(letterG, CRGB(255,0,0));
//  displayLetter(letterH, CRGB(255,0,0));
//  displayLetter(letterI, CRGB(255,0,0));
//  displayLetter(letterJ, CRGB(255,0,0));
//  displayLetter(letterK, CRGB(255,0,0));
//  displayLetter(letterL, CRGB(255,0,0));
//  displayLetter(letterM, CRGB(255,0,0));
//  displayLetter(letterN, CRGB(255,0,0));
//  displayLetter(letterO, CRGB(255,0,0));
//  displayLetter(letterP, CRGB(255,0,0));
//  displayLetter(letterQ, CRGB(255,0,0));
//  displayLetter(letterR, CRGB(255,0,0));
//  displayLetter(letterS, CRGB(255,0,0));
//  displayLetter(letterT, CRGB(255,0,0));
//  displayLetter(letterU, CRGB(255,0,0));
//  displayLetter(letterV, CRGB(255,0,0));
//  displayLetter(letterW, CRGB(255,0,0));
//  displayLetter(letterX, CRGB(255,0,0));
//  displayLetter(letterY, CRGB(255,0,0));
//  displayLetter(letterZ, CRGB(255,0,0));
  
  // You can add other animations or logic here
}

void slideText(const char* text, CRGB color) {
  int textLength = strlen(text);
  int displayWidth = MATRIX_WIDTH + textLength*3;

  for (int i = 0; i <= displayWidth; ++i) {
    // Clear the display
    fill_solid(leds, NUM_LEDS, CRGB::Black);

    // Display the sliding text
    int textStart = max(0, i - MATRIX_WIDTH);
    int textEnd = min(i, textLength);

    for (int col = textStart; col < textEnd; ++col) {
      char character = text[col];
      const char* letterArray = getLetterArray(character);

      for (int row = 0; row < MATRIX_HEIGHT; ++row) {
        for (int colInLetter = 0; colInLetter < 3; ++colInLetter) {
          int ledIndex = ledLayout[row][col * 3 + colInLetter] - 1;
          leds[ledIndex] = (letterArray[row] & (1 << colInLetter)) ? color : CRGB::Black;
        }
      }
    }

    FastLED.show();
    delay(100); // Adjust the delay based on your desired animation speed
  }
}

const char* getLetterArray(char character) {
  switch (character) {
    case 'A': return reinterpret_cast<const char*>(letterA);
    // Add cases for other letters...
    case 'Z': return reinterpret_cast<const char*>(letterZ);
    default: return nullptr; // Return null for unknown characters
  }
}
