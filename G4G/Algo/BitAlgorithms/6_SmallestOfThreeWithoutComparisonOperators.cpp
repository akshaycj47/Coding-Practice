#include <climits>
#include <cassert>

/**
* Function that returns the minimum of three numbers without
* using comparison operators. This particular method uses
* repeated subtraction. This method won't work for negative numbers.
* @params {int} x - First number
* @params {int} y - Second number
* @params {int} z - Third number
* @return {int} Minimum of three numbers
*/
int smallestOfThreeRepeatedSubtraction(int x, int y, int z) {

	int c = 0;
	while (x && y && z) {
		x--;
		y--;
		z--;
		c++;
	}
	return c;
}

/**
* Function that returns the sign bit of subtraction of two numbers.
* Sign bit can be obtained by subtracting two numbers and right 
* shifting the result by 31 (if the size of integer is 32).
* @params {int} x - First number
* @params {int} y - Second number
* @return {int} Sign bit of x - y
*/
int getSignBit(int x, int y) {

	return (x - y) >> (sizeof(int)* CHAR_BIT - 1);
}

/**
* Function that returns the minimum of two numbers without
* using comparison operators. This particular method uses
* bit operators
* @params {int} x - First number
* @params {int} y - Second number
* @return {int} Minimum of two numbers
*/
int minTwo(int x, int y) {

	return y + ((x - y) & getSignBit(x, y));
}

/**
* Function that returns the minimum of three numbers without
* using comparison operators. This particular method uses
* bit operators
* @params {int} x - First number
* @params {int} y - Second number
* @params {int} z - Third number
* @return {int} Minimum of three numbers
*/
int minThree(int x, int y, int z) {

	return minTwo(x, minTwo(y, z));
}

/**
* Starting point of the program
*/
int main() {

	assert(smallestOfThreeRepeatedSubtraction(5, 7, 12) == 5);
	assert(smallestOfThreeRepeatedSubtraction(13, 15, 13) == 13);
	assert(smallestOfThreeRepeatedSubtraction(12, 0, 91) == 0);
	assert(smallestOfThreeRepeatedSubtraction(-15, 9, 25) != -15);

	assert(minThree(5, 7, 12) == 5);
	assert(minThree(13, 15, 13) == 13);
	assert(minThree(12, 0, 91) == 0);
	assert(minThree(-15, 9, 25) == -15);
}