#include <stdlib.h>
#include "halfsiphash.h"
#include "siphash.h"

typedef uint8_t u8;

#define ARRAY(name, size) \
    u8 name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

void sip(void) {
	ARRAY(in, 64);
	ARRAY(out, 64);
	ARRAY(key, 16);

	for(size_t i = 0; i < 64; i++) {
		siphash(in, i, key, out, 8);
		siphash(in, i, key, out, 16);
	}
}

void half(void) {
	ARRAY(in, 64);
	ARRAY(out, 64);
	ARRAY(key, 16);

	for(size_t i = 0; i < 64; i++) {
		halfsiphash(in, i, key, out, 4);
		halfsiphash(in, i, key, out, 8);
	}
}


int main(void) {
	sip();
	half();
	return 0;
}
