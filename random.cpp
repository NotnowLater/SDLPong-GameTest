#include "random.h"

int Random::Rng(int min, int max) {
	int rn = (std::rand() % max) + min;
	std::cout << rn << std::endl;
	return rn;
}