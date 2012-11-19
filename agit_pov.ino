/*
 * AgitPOV
 * 7-LED POV for Arduino
 *
 * (c) 2011 Alexandre Castonguay
 *          Sofian Audry
 *          Jean-Pascal Bellemare
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

#define USE_LATIN
//#define USE_ARABIC

typedef uint16_t letter_t;

// nous aurons besoin de comparer le temps écoulé entre deux lectures du senseur reed

unsigned long oldmillis = 42;
unsigned long newmillis = 46;
unsigned long laps = 666;
unsigned long intervalle = 0;

//set up pin 0 - 7 as OUTPUT
void setup()
{  
// Serial.begin(9600);
  for (int k=0;k<7;k++) 
    pinMode(k,OUTPUT);
}

//method of displaying the letters. displaying each column (one hex number) of the letter one by one through PORTD. then after a letter, it puts a space in between and move onto the next letter. until however long of the String you wish to display.
//each letter is first turned into ASCII integer, then minus 65. It would then be the row of the letter from the library above. (ex. A is 65 in ASCII, but row 0 in my library)
// furthermore, because of the way i made the hardware, it displays each letter starting from the back of the sentence, and each letter from the right most column.

void display(letter_t message[], size_t length)
{
  for (int i = length-1; i>=0; i--)
  {
    for (int j = (WIDTH-1); j>=0; j--)
    {
      PORTD = font[(int)string[i]-0][j];
      delayMicroseconds(3000);
    }
    PORTD = B00000000;
    delayMicroseconds(5050);
  }
}

// you simply feed a string to display it. this code only allows capital letters. however, if you add characters or lowercases in the library above, it would also be able to display it. (but then it would minus a different number instead of 65 above)

void loop()
{
  
  if ( analogRead(5)==1023 ) // ATTENTION! REEED REEED!!!
  {
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
    display( { 1, 2, 3, 4 }, 4 );
    //display("BONJOUR");
  }
}

