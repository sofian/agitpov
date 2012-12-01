/*
 * AgitPOV
 * 7-LED POV for Arduino
 * Can display both latin and arabic letters.
 *
 * (c) 2011-2012
 *       Alexandre Castonguay
 *       Sofian Audry
 *       Jean-Pascal Bellemare
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Letter width. since i have 7 LED, then each letter would look like a 7 x 5 matrix
#define WIDTH 5
#define MAX_MESSAGE_LENGTH 10

#define USE_LATIN
#define USE_ARABIC

#include <avr/pgmspace.h>

#include "latin_chars.h"
#include "arabic_chars.h"

// nous aurons besoin de comparer le temps écoulé entre deux lectures du senseur reed

unsigned long oldmillis = 42;
unsigned long newmillis = 46;
unsigned long laps = 667;
unsigned long intervalle = 500;

// Set up pin 0 - 7 as OUTPUT.
void setup()
{  
  Serial.begin(9600);
  for (int k=0;k<7;k++) 
    pinMode(k,OUTPUT);
}

//method of displaying the letters. displaying each column (one hex number) of the letter one by one through PORTD. then after a letter, it puts a space in between and move onto the next letter. until however long of the String you wish to display.
//each letter is first turned into ASCII integer, then minus 65. It would then be the row of the letter from the library above. (ex. A is 65 in ASCII, but row 0 in my library)
// furthermore, because of the way i made the hardware, it displays each letter starting from the back of the sentence, and each letter from the right most column.
void display(prog_uchar fontSet[][WIDTH], int16_t* message, size_t length, unsigned long spaceBetweenLetters=2000, unsigned long spaceBetweenColumns=1000)
//void display(uint8_t fontSet[][WIDTH], int16_t* message, size_t length)
{
  length = min(length, MAX_MESSAGE_LENGTH);
  for (int i = length-1; i>=0; i--)
  {
    for (int j = (WIDTH-1); j>=0; j--)
    {
      byte b = pgm_read_byte(&fontSet[message[i]][j]);//message[(int)POVstring[i]-0][j];
//      byte b = fontSet[message[i]][j];
      for (int k=0; k<7; k++)
        digitalWrite(k, bitRead(b, k));
      delayMicroseconds(spaceBetweenColumns+1);
    }
    for (int k=0; k<7; k++)
      digitalWrite(k, 0);
    delayMicroseconds(spaceBetweenLetters+1);
//    delayMicroseconds(5050);
  }
}

#ifdef USE_LATIN
void displayLatin(const char* msg) {
  int16_t alphaMsg[MAX_MESSAGE_LENGTH];
  latin_str2alpha(alphaMsg, msg);
  display(LATIN_CHARS, alphaMsg, strlen(msg), 4500, 3300);
}
#endif

#ifdef USE_ARABIC
void displayArabic(int16_t* msg, size_t length) {
  display(ARABIC_CHARS, msg, length, 0, 4000);
}
#endif

// you simply feed a string to display it. this code only allows capital letters. however, if you add characters or lowercases in the library above, it would also be able to display it. (but then it would minus a different number instead of 65 above)

void loop()
{
  
//  if ( analogRead(5)==1023 ) // ATTENTION! REEED REEED!!!
//  {
    newmillis = millis();
    // Serial.print("old = ");
    // Serial.println(oldmillis);
    // Serial.print("new = ");
    //  Serial.println(newmillis);
    laps = newmillis-oldmillis;
    oldmillis = newmillis;
    //  Serial.print("rpm = ");
    // Serial.println(laps);

    intervalle = min(laps/3, 400);
    //Serial.println(intervalle);
    //  Serial.println();
    delay(intervalle);

 //displayLatin("WADI");
 
 //    displayArabic( (int16_t[]){ kaf_ini, ra_end, ya_ini, mim_end }, 4);
//    displayArabic( (int16_t[]) { alif_iso, jim_iso, mim_iso, sin_end1, sin_end2 }, 5);
//    displayArabic( (int16_t[]){ mim_ini, ra_end, ha_ini, ba_med, alif_end }, 5);
//    displayArabic( (int16_t[]){ jim_iso }, 1);
//      displayArabic( (int16_t[]){ alif_ini, heh_ini, la_end }, 3);
/////////    displayArabic( (int16_t[]){ ta_ini, waw_end, nun_ini,sin_end1,sin_end2 }, 5);

      // !!!IMPORTANT!!! Il faut ecrire de droite a gauche comme en arabe
      displayArabic( (int16_t[]){ ya_end, dal_med, heh_ini }, 3);
//      displayArabic( (int16_t[]){ mim_ini, hamzah_end }, 2);
    
//    displayArabic( (int16_t[]){ sin_ini, la_med, alif_med, mim_ini, space, ayn_ini, la_med, ya_med, kaf_med, mim_end }, 10);
//display("BONJOUR");
//  }
}

