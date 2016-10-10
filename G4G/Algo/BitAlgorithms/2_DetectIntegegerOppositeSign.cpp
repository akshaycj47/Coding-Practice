#include <cassert>

/**
* Function that checks if the two integers have same sign or opposite
* @params {int} x - First integer
* @params {int} y - Second integer
* @return {bool} True if two integers have opposite sign, False if
* two integers have same sign
*/
bool detectOppositeSign(int x, int y) {

	return (x ^ y) < 0;
}

/**
* Starting point of the program
*/
int main() {

	assert(detectOppositeSign(5, -12) == true);
	assert(detectOppositeSign(-15, 56) == true);
	assert(detectOppositeSign(-7, -9) == false);
	assert(detectOppositeSign(-5, 0) == true);
	assert(detectOppositeSign(3, -3) == true);
}