#include "knobs.h"

knobs::knobs() {

}

unsigned char knobs::type1(unsigned char value, unsigned char diff) {

	return diff + value;

}
