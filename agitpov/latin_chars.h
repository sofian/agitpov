#include <string.h>

void latin_str2alpha(int16_t *dst, const char* str) {
  for (int i=0; i<strlen(str); i++) {
    char c = str[i];
    int16_t a;
    if ('a' <= c && c <= 'z')
      c += 26; // uppercase
    if ('A' <= c && c <= 'Z')
      a = (c - 'A') + 7;
    else {
      switch (c) {
        case ' ': a = 0; break;
        case '!': a = 1; break;
        case '+': a = 2; break;
        case '.': a = 3; break;
        case '/': a = 4; break;
        case '=': a = 5; break;
        case '?': a = 6; break;
        default : a = 0; break;
      }
    }

    dst[i] = a;
  }
}

uint8_t PROGMEM LATIN_CHARS [][5] =
//uint8_t LATIN_CHARS [][5] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00}, //space
	{0x00, 0x00, 0x5f, 0x00, 0x00}, //!
	{0x08, 0x08, 0x3e, 0x08, 0x08}, //+
	{0x40, 0x00, 0x00, 0x00, 0x00}, //.
	{0x3e, 0x41, 0x41, 0x41, 0x3e}, // /
	{0x14, 0x14, 0x14, 0x14, 0x14}, //=
	{0x00, 0x02, 0x59, 0x09, 0x06}, //?
	{0x7e, 0x09, 0x09, 0x09, 0x7e}, //A
	{0x7f, 0x49, 0x49, 0x49, 0x36}, //B
	{0x3e, 0x41, 0x41, 0x41, 0x22}, //C
	{0x7f, 0x41, 0x41, 0x22, 0x1c}, //D
	{0x7f, 0x49, 0x49, 0x49, 0x49}, //E
	{0x7f, 0x09, 0x09, 0x09, 0x09}, //F
	{0x7e, 0x41, 0x49, 0x49, 0x38}, //G
	{0x7f, 0x08, 0x08, 0x08, 0x7f}, //H
	{0x00, 0x41, 0x7f, 0x41, 0x00}, //I
	{0x30, 0x40, 0x41, 0x7f, 0x01}, //J
	{0x7f, 0x08, 0x14, 0x22, 0x41}, //K
	{0x7f, 0x40, 0x40, 0x40, 0x40}, //L
	{0x7f, 0x02, 0x04, 0x02, 0x7f}, //M
	{0x7f, 0x02, 0x0c, 0x10, 0x7f}, //N
	{0x3e, 0x41, 0x41, 0x41, 0x3e}, //O
	{0x7f, 0x09, 0x09, 0x09, 0x06}, //P                          
	{0x1e, 0x21, 0x21, 0x21, 0x5e}, //Q
	{0x7f, 0x09, 0x19, 0x29, 0x46}, //R
	{0x26, 0x49, 0x49, 0x49, 0x32}, //S
	{0x01, 0x01, 0x7f, 0x01, 0x01}, //T
	{0x3f, 0x40, 0x40, 0x40, 0x3f}, //U
	{0x07, 0x38, 0x40, 0x38, 0x07}, //V
	{0x3f, 0x40, 0x3f, 0x40, 0x3f}, //W
	{0x63, 0x14, 0x08, 0x14, 0x63}, //X
	{0x07, 0x08, 0x70, 0x08, 0x07}, //Y
	{0x61, 0x51, 0x49, 0x45, 0x43}  //Z  
};

