/*
 * Random.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */

#ifndef RANDOM_C_
#define RANDOM_C_

#include "logic/Random.h"

const unsigned int PRIMES[16] = {
	2,
	3,
	5,
	7,
	11,
	13,
	17,
	19,
	23,
	29,
	31,
	37,
	41,
	43,
	47,
	53
};

#define WRAP(x) ( (x) & 15 )

unsigned int index = 0;

int getRandomNum() {
	int seed = WRAP(PRIMES[index]);
	index = WRAP(index + 1);

	int num = PRIMES[index];
	for(int i=0; i<seed; i++) {
		num *= PRIMES[index];
		index = WRAP(index + PRIMES[index]);
		num >>= WRAP(PRIMES[index]);

		index = WRAP(index * PRIMES[index]);
	}

	return num;
}

#endif /* RANDOM_C_ */
