/*
 * Arabic chars
 * 7-LED POV for Arduino
 *
 * (c) 2012 Sofian Audry
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

// Examples:
// display( { kaf_ini, ra_end, ya_ini, mim_end }, 4);
// display( { sin_ini, la_med, mim_ini, space, ayn_ini, la_med, ya_med, kaf_med, mim_end }, 9);

// (*) personal add, not in original PDF
// (**) must be followed by long end
// (***) waw_end with hamzah must use hamzah_waw_end

#define long_end 84 // must follow sin_end1, shin_end1, sad_end1 and dad_end1

#define space 85

#define alif_iso   0
#define alif_ini   0
#define alif_med   1
#define alif_end   1

#define ba_iso   2
#define ba_ini   3
#define ba_med   4
#define ba_end   2

#define ta_iso   5
#define ta_ini   6
#define ta_med   7
#define ta_end   5

#define tha_iso   8
#define tha_ini   9
#define tha_med  10
#define tha_end   8

#define jim_iso  11
#define jim_ini  12
#define jim_med  13
#define jim_end  14

#define ha_iso  15
#define ha_ini  16
#define ha_med  17
#define ha_end  18

#define kha_iso  19
#define kha_ini  20
#define kha_med  21
#define kha_end  22

#define dal_iso  23
#define dal_ini  23
#define dal_med  24
#define dal_end  24

#define zal_iso  25
#define zal_ini  25
#define zal_med  26
#define zal_end  26

#define ra_iso  27
#define ra_ini  27
#define ra_med  28
#define ra_end  28

#define zay_iso  29
#define zay_ini  29
#define zay_med  30
#define zay_end  30

#define sin_iso1  32
#define sin_iso2  long_end
#define sin_ini  31
#define sin_med  31
#define sin_end1 32
#define sin_end2 long_end

#define shin_iso1 34
#define shin_iso2  long_end
#define shin_ini  33
#define shin_med  33
#define shin_end1 34
#define shin_end2 long_end

#define sad_iso1 36
#define sad_iso2 long_end
#define sad_ini  35
#define sad_med  35
#define sad_end1 36
#define sad_end2 long_end

#define ta_iso  39
#define ta_ini  39
#define ta_med  39
#define ta_end  39

#define zha_iso  40
#define zha_ini  40
#define zha_med  40
#define zha_end  40

#define ayn_iso  41
#define ayn_ini  42
#define ayn_med  43
#define ayn_end  44

#define ghayn_iso  45
#define ghayn_ini  46
#define ghayn_med  47
#define ghayn_end  48

#define fa_iso  49
#define fa_ini  50
#define fa_med  51
#define fa_end  52

#define qaf_iso  53
#define qaf_ini  54
#define qaf_med  55
#define qaf_end  56

#define qaf_iso  53
#define qaf_ini  54
#define qaf_med  55
#define qaf_end  56

#define kaf_iso  57
#define kaf_ini  58
#define kaf_med  59
#define kaf_end  57

#define lam_iso  60
#define lam_ini  61
#define lam_med  62
#define lam_end  60

#define mim_iso  63
#define mim_ini  64
#define mim_med  65
#define mim_end  66

#define nun_iso  67
#define nun_ini  68
#define nun_med  69
#define nun_end  67

#define heh_iso  70
#define heh_ini  71
#define heh_med  72
#define heh_end  73

#define waw_iso  74
#define waw_ini  74
#define waw_med  75
#define waw_end  75

#define la_iso  76
#define la_ini  76
#define la_med  77
#define la_end  77

#define ya_iso  78
#define ya_ini  79
#define ya_med  80
#define ya_end  78

#define hamzah_iso  81
#define hamzah_ini  82
#define hamzah_med  82
#define hamzah_end  83

uint8_t PROGMEM ARABIC_CHARS [][5] = {
//uint8_t ARABIC_CHARS[][5] = {
  
/*0*/	{ 0x00, 0x00, 0x7c, 0x00, 0x00, }, // alif_iso & alif_ini
	{ 0x00, 0x00, 0x7c, 0x04, 0x04, }, // alif_med & alif_end

	{ 0x0c, 0x04, 0x05, 0x04, 0x0c, }, // ba_iso & ba_end
	{ 0x04, 0x04, 0x05, 0x0c, 0x00, }, // ba_ini
	{ 0x04, 0x04, 0x0d, 0x04, 0x04, }, // ba_med

/*5*/	{ 0x0c, 0x24, 0x04, 0x24, 0x0c, }, // ta_iso & ta_end
	{ 0x24, 0x04, 0x24, 0x0c, 0x00, }, // ta_ini
	{ 0x04, 0x24, 0x0c, 0x24, 0x04, }, // ta_med

	{ 0x0c, 0x24, 0x44, 0x24, 0x0c, }, // tha_iso & tha_end
	{ 0x24, 0x44, 0x24, 0x0c, 0x00, }, // tha_ini
/*10*/	{ 0x04, 0x24, 0x4c, 0x24, 0x04, }, // tha_med

	{ 0x26, 0x29, 0x31, 0x35, 0x20, }, // jim_iso
	{ 0x14, 0x14, 0x15, 0x0c, 0x04, }, // jim_med
	{ 0x04, 0x14, 0x15, 0x14, 0x0c, }, // jim_ini
	{ 0x27, 0x29, 0x30, 0x32, 0x28, }, // jim_end

/*15*/	{ 0x26, 0x29, 0x31, 0x30, 0x20, }, // ha_iso
	{ 0x04, 0x14, 0x14, 0x14, 0x0c, }, // ha_ini
	{ 0x14, 0x14, 0x14, 0x0c, 0x04, }, // ha_med (*)
	{ 0x26, 0x29, 0x31, 0x30, 0x28, }, // ha_end

	{ 0x12, 0x15, 0x59, 0x19, 0x10, }, // kha_iso
/*20*/	{ 0x04, 0x14, 0x54, 0x14, 0x0c, }, // kha_ini
	{ 0x04, 0x14, 0x54, 0x0c, 0x04, }, // kha_med
	{ 0x12, 0x15, 0x59, 0x19, 0x14, }, // kha_end

	{ 0x00, 0x02, 0x12, 0x0e, 0x00, }, // dal_iso & dal_ini
	{ 0x00, 0x02, 0x12, 0x0e, 0x02, }, // dal_med & dal_end

/*25*/	{ 0x00, 0x02, 0x52, 0x0e, 0x00, }, // zal_iso & zal_ini
	{ 0x00, 0x02, 0x52, 0x0e, 0x02, }, // zal_med & zal_end

	{ 0x01, 0x01, 0x02, 0x0c, 0x00, }, // ra_iso & ra_ini
	{ 0x01, 0x01, 0x02, 0x0c, 0x04, }, // ra_med & ra_end

	{ 0x01, 0x01, 0x02, 0x2c, 0x00, }, // zay_iso & zay_ini
/*30*/	{ 0x01, 0x01, 0x02, 0x2c, 0x04, }, // zay_med & zay_end

	{ 0x0c, 0x04, 0x0c, 0x04, 0x0c, }, // sin_ini & sin_med
	{ 0x04, 0x0c, 0x04, 0x0c, 0x00, }, // sin_iso & sin_end (**)

	{ 0x0c, 0x24, 0x4c, 0x24, 0x0c, }, // shin_ini & shin_med
	{ 0x24, 0x4c, 0x24, 0x0c, 0x04, }, // shin_iso & shin_end (**)

/*35*/	{ 0x0c, 0x04, 0x0e, 0x14, 0x1c, }, // sad_ini & sad_med
	{ 0x04, 0x0e, 0x14, 0x1c, 0x00, }, // sad_iso & sad_end (**)

	{ 0x0c, 0x04, 0x4e, 0x14, 0x1c, }, // dad_ini & dad_med
	{ 0x44, 0x0e, 0x14, 0x1c, 0x04, }, // dad_iso & dad_end (**)

	{ 0x04, 0x7e, 0x14, 0x14, 0x0c, }, // ta_all

/*40*/	{ 0x04, 0x7e, 0x14, 0x54, 0x0c, }, // zha_all

	{ 0x06, 0x09, 0x71, 0x51, 0x10, }, // ayn_iso
	{ 0x04, 0x04, 0x0c, 0x14, 0x14, }, // ayn_ini
	{ 0x04, 0x14, 0x1c, 0x14, 0x04, }, // ayn_med
	{ 0x06, 0x09, 0x31, 0x31, 0x08, }, // ayn_end

/*45*/	{ 0x46, 0x09, 0x71, 0x51, 0x10, }, // ghayn_iso
	{ 0x04, 0x04, 0x5c, 0x14, 0x04, }, // ghayn_ini
	{ 0x04, 0x14, 0x5c, 0x14, 0x04, }, // ghayn_med
	{ 0x46, 0x09, 0x31, 0x31, 0x08, }, // ghayn_end

	{ 0x0c, 0x44, 0x04, 0x34, 0x38, }, // fa_iso
/*50*/	{ 0x44, 0x04, 0x34, 0x3c, 0x00, }, // fa_ini
	{ 0x04, 0x1c, 0x54, 0x1c, 0x04, }, // fa_med
	{ 0x0c, 0x44, 0x04, 0x34, 0x3c, }, // fa_end

	{ 0x06, 0x01, 0x49, 0x19, 0x5e, }, // qaf_iso
	{ 0x44, 0x44, 0x04, 0x34, 0x38, }, // qaf_ini
/*55*/	{ 0x04, 0x5c, 0x14, 0x5c, 0x04, }, // qaf_med
	{ 0x0c, 0x02, 0x41, 0x1a, 0x5c, }, // qaf_end

	{ 0x16, 0x72, 0x52, 0x02, 0x7c, }, // kaf_iso & kaf_end
	{ 0x04, 0x24, 0x54, 0x4c, 0x40, }, // kaf_ini
	{ 0x04, 0x24, 0x54, 0x4c, 0x44, }, // kaf_med

/*60*/	{ 0x06, 0x01, 0x01, 0x01, 0x3e, }, // lam_iso & lam_end
	{ 0x04, 0x04, 0x04, 0x7c, 0x00, }, // lam_ini
	{ 0x04, 0x04, 0x7c, 0x04, 0x04, }, // lam_med

	{ 0x1f, 0x70, 0x50, 0x70, 0x00, }, // mim_iso
	{ 0x02, 0x02, 0x03, 0x05, 0x07, }, // mim_ini
/*65*/	{ 0x08, 0x0c, 0x14, 0x1c, 0x08, }, // mim_med
	{ 0x1f, 0x30, 0x50, 0x70, 0x08, }, // mim_end

	{ 0x0e, 0x01, 0x21, 0x01, 0x0e, }, // nun_iso & nun_end
	{ 0x04, 0x04, 0x24, 0x04, 0x18, }, // nun_ini
	{ 0x04, 0x04, 0x2c, 0x04, 0x04, }, // nun_med

/*70*/	{ 0x00, 0x5c, 0x14, 0x5c, 0x00, }, // heh_iso
	{ 0x14, 0x24, 0x4c, 0x54, 0x7c, }, // heh_ini
	{ 0x04, 0x1f, 0x15, 0x0e, 0x04, }, // heh_med
	{ 0x00, 0x30, 0x50, 0x7c, 0x04, }, // heh_end

	{ 0x01, 0x0d, 0x15, 0x1e, 0x00, }, // waw_iso & waw_ini
/*75*/	{ 0x01, 0x0d, 0x15, 0x1e, 0x04, }, // waw_med & waw_end (***)

	{ 0x04, 0x74, 0x0c, 0x7c, 0x00, }, // la_iso & la_ini 
	{ 0x04, 0x74, 0x0c, 0x7c, 0x04, }, // la_med & la_end (*)

	{ 0x06, 0x01, 0x0d, 0x13, 0x08, }, // ya_iso & ya_end
	{ 0x05, 0x04, 0x05, 0x04, 0x08, }, // ya_ini
/*80*/	{ 0x04, 0x05, 0x0c, 0x05, 0x04, }, // ya_med

	// Special cases
	{ 0x00, 0x04, 0x0c, 0x14, 0x00, }, // hamzah_iso
	{ 0x14, 0x74, 0x54, 0x04, 0x08, }, // hamzah_ini & hamzah_med
	{ 0x00, 0x00, 0x10, 0x30, 0x50, }, // hamzah_end

	{ 0x0e, 0x01, 0x01, 0x01, 0x0e, }, // long end: must follow sin_end, shin_end, sad_end and dad_end

/*85*/	{ 0x00, 0x00, 0x00, 0x00, 0x00, }, // space
};











