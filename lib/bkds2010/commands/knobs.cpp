#include "knobs.h"

knobs::knobs() {

}

void knobs::type1(unsigned char value[2], unsigned char diff) {

	bool min = false;
	bool max = false;

	if(((signed int)value[1] + (signed char)diff) > 0xff) {
		if(value[0] < 0xff) {
			value[0]++;
		} else {
			max = true;
		}
	} else if(((signed int)value[1] + (signed char)diff) < 0x00) {
		if(value[0] > 0x00) {
			value[0]--;
		} else {
			min = true;
		}
	}

	if(max) {
		value[1] = 0xff;
	} else if(min) {
		value[1] = 0x00;
	} else {
		value[1] += diff;
	}

}

void knobs::type2(unsigned char value[2], unsigned char diff) {

	if(((signed int)value[1] + (signed char)diff) > 0xff) {
		value[0]++;
	} else if(((signed int)value[1] + (signed char)diff) < 0x00) {
		value[0]--;
	}

	value[1] += diff;
}
