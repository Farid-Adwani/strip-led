#include <FastLED.h>

#define MATRIX_WIDTH 34
#define MATRIX_HEIGHT 7
#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)
#define DATA_PIN 21

CRGB leds[NUM_LEDS];

int verticalOffset = 1 ;

int ledLayout[MATRIX_HEIGHT][MATRIX_WIDTH] = {
{234,235,236,237,238,239,240,241,242,243,244,245,247,248,249,250,251,252,253,254,255,256,258,259,260,261,262,263,264,265,266,267,269,270},
{230, 229, 228, 227, 226, 225, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 197, 196, 195, 194},
{156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,177,178,179,180,181,182,183,184,185,186,187,188,189,190},
{152, 151, 150, 149, 148, 147, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117},
{79,80,81,82,83,84,85,86,87,88,89,90,91,92,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113 },
{75, 74, 73, 72, 71, 70, 69, 68, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20,21,22,23,24,25,26,27,28,29,31,32,33,34,35,36}
};


const char letterA[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};

const char letterB[][6] = {
  {1,1, 1, 1, 0,0},
  {1,1, 0, 0, 1,1},
  {1,1, 1, 1, 0,0},
  {1,1, 0, 0, 1,1},
  {1,1, 1, 1, 0,0}
};

const char letterC[][6] = {
  {0,0, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0},
  {0,0, 1, 1, 1, 1}
};

const char letterD[][6] = {
  {1,1, 1, 1, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 0, 0}
};


const char letterE[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 1, 1}
};


const char letterF[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0}
};


const char letterG[][6] = {
  {0,0, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {0,0, 1, 1, 1, 1}
};

const char letterH[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};

const char letterI[][6] = {
  {1,1, 1, 1, 1, 1},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0},
  {1,1, 1, 1, 1, 1}
};

const char letterJ[][6] = {
  {0,0, 0, 0, 1, 1},
  {0,0, 0, 0, 1, 1},
  {0,0, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1}
};


const char letterK[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterL[][6] = {
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 1, 1}
};


const char letterM[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterN[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterO[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1}
};


const char letterP[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 0, 0, 0, 0}
};


const char letterQ[][6] = {
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {0,0, 0, 0, 1, 1},
  {0,0, 0, 0, 1, 1}
};


const char letterR[][6] = {
  {1,1, 1, 1, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterS[][6] = {
  {0,0, 1, 1, 1, 1},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 0, 0},
  {0,0, 0, 0, 1, 1},
  {1,1, 1, 1, 0, 0}
};


const char letterT[][6] = {
  {1,1, 1, 1, 1, 1},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0}
};


const char letterU[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1}
};


const char letterV[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {0,0, 1, 1, 0, 0}
};


const char letterW[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterX[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {0,0, 1, 1, 0, 0},
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1}
};


const char letterY[][6] = {
  {1,1, 0, 0, 1, 1},
  {1,1, 0, 0, 1, 1},
  {1,1, 1, 1, 1, 1},
  {0,0, 1, 1, 0, 0},
  {0,0, 1, 1, 0, 0}
};


const char letterZ[][6] = {
  {1,1, 1, 1, 1, 1},
  {0,0, 0, 0, 1, 1},
  {0,0, 1, 1, 0, 0},
  {1,1, 0, 0, 0, 0},
  {1,1, 1, 1, 1, 1}
};


const char Space[][6] = {
  {0,0, 0, 0, 0, 0},
  {0,0, 0, 0, 0, 0},
  {0,0, 0, 0, 0, 0},
  {0,0, 0, 0, 0, 0},
  {0,0, 0, 0, 0, 0},
};
const char letterSpace[][2] = {
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}
};


void displayLetter(const char letter[5][6], CRGB color , int index , int height) {
  // Clear the display
  // Display the letter
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 6;col++) {

        if(col+index >=0 && (col+index) < MATRIX_WIDTH ){
          int ledIndex = ledLayout[row+height][col+index];
             CRGB new_color(0,0,0);
            if((ledIndex-1)>196){
              new_color=CRGB(color.r,color.b,color.g);
            }else{
              new_color=color;
            }
            leds[ledIndex-1] = (letter[row][col] == 1) ? new_color : CRGB::Black;
        }

      
  
    }
  }


}


void displaySpace(int index , int height) {
  // Clear the display
  

  // Display the letter
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 2;col++) {

        if(col+index >=0 && (col+index) < MATRIX_WIDTH ){
          int ledIndex = ledLayout[row+height][col+index];
            leds[ledIndex-1] = CRGB::Black;
        }

      
  
    }
  }

  
}


void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


const char (*convertChar(char c))[6]{
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
    case ' ': return Space;

    default: return nullptr; // Default case if character is not found
  }
}



void displaySentence( String sentence){

  CRGB color(0,0,255);
  int offset = MATRIX_WIDTH - 2 ;
   
   while (true) {
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
   for (int i = 0; i < sentence.length()  ; i++) {
    
    if(i%2 == 0){
      color=CRGB(0,0,100);
    }else{
      color=CRGB(0,100,0);
    }


    
    

    if(i==sentence.length()-1){
      if(i*8 + offset <= -8){
        offset = MATRIX_WIDTH - 2 ;
      }
    }
    
  
    
      displayLetter(convertChar(sentence[i]), color,i*8 + offset,verticalOffset);
      //displaySpace(i*8+ offset,verticalOffset);
    
   }
     FastLED.show();
     delay(200);
   offset -= 2 ;
   }
  
}



void loop() {
  FastLED.setBrightness(255);

//   leds[15] = CRGB(255,0,0);
//   FastLED.show();
//     delay(2000);
  // Example: Slide the text "HELLO" from right to left
  //displaySentence("HELLO");

  displaySentence("AEROBOTIX INSAT");
//  fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
//  FastLED.show();
//    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
//
//  displayLetter(letterA, CRGB(0,0,255),0,verticalOffset);
//  FastLED.show();
//  delay(2000);
//  displayLetter(letterB, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterC, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterD, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterE, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterF, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterG, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterH, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterI, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterJ, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterK, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterL, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterM, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterN, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterO, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterP, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterQ, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterR, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterS, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterT, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterU, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterV, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterW, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterX, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterY, CRGB(255,0,0),0,verticalOffset);
//  displayLetter(letterZ, CRGB(255,0,0),0,verticalOffset);
  
  // You can add other animations or logic here
}
