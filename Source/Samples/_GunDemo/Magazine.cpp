#include "Magazine.h"



Magazine::Magazine(int capacity = 0, int loaded = 0) {
	maximumCapacity = capacity;
	roundsLoaded = loaded;
}

bool Magazine::loadRound() {
	if (roundsLoaded++ > maximumCapacity) {
		roundsLoaded--;
		return false;
	}
	return true;
}

bool Magazine::removeRound() {
	if (roundsLoaded-- < 0) {
		roundsLoaded = 0;
		return false;
	}
	return true;
}

Magazine::~Magazine() {
}
