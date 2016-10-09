#include <cassert>
#include <iostream>

/**
* Function that checks if a given number is an ugly number
* Ugly numbers are numbers whose only prime factors are 2, 3, or 5
* @params {int} num - Number for which we have to check if it is ugly
* @return {bool} true if number is ugly, else false
*/
bool isUgly(int num) {

	if (num == 0) return false;
	while (num % 2 == 0) num = num / 2;
	while (num % 3 == 0) num = num / 3;
	while (num % 5 == 0) num = num / 5;
	return num == 1;
}

/**
* Function that returns nth ugly number
* Ugly numbers are numbers whose only prime factors are 2, 3, or 5
* Simple approach would be to keep a counter and check all integers starting
* from 1 to see if they are ugly or not
* @params {int} n
* @return {int} nth ugly number
*/
int nthUglyNumber(int n) {

	int count = 0;
	int i = 1;
	while (count < n) {
		if (isUgly(i)) {
			count++;
		}
		i++;
	}
	return i - 1;
}

/**
* Starting point of the program
*/
int main() {

	assert(isUgly(12) == true);
	assert(isUgly(17) == false);
	assert(isUgly(0) == false);
	assert(isUgly(1) == true);
	assert(nthUglyNumber(150) == 5832);
	assert(nthUglyNumber(200) == 16200);
	assert(nthUglyNumber(56) == 320);
	assert(nthUglyNumber(91) == 1200);
}