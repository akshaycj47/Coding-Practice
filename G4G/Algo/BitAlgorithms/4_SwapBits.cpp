#include <cstdint>
#include <cmath>
#include <cassert>
#include <iostream>

int swapBits(uint32_t num, uint32_t p1, uint32_t p2, uint32_t n) {

	uint32_t mask = pow(2, n) - 1;
	uint32_t first = (mask << p1) & num;
	uint32_t second = (mask << p2) & num;

	// Create gaps in the number for swap
	num = ~(mask << p1) & num;
	num = ~(mask << p2) & num;

	// Start the swap
	first = first >> p1;
	first = first << p2;
	second = second >> p2;
	second = second << p1;
	num = first | num;
	num = second | num;

	return num;
}

int main() {

	assert(swapBits(47, 1, 5, 3) == 227);
	assert(swapBits(28, 0, 3, 2) == 7);
}