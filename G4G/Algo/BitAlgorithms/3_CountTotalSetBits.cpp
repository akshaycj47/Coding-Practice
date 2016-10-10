#include <cassert>

/**
* Function that counts number of set bits in a given number
* @params {int} num - Given number
* @return {int} Number of set bits in a given number
*/
int totalSetBitsSingleNumber(int num) {

	int count = 0;
	while (num != 0) {
		if (num % 2 == 1) {
			count++;
		}
		num = num / 2;
	}
	return count;
}

/**
* Function that counts number of set bits in binary representation of 
* all numbers from 1 to n
* @params {int} n
* @return {int} Number of set bits in binary representation of all 
* numbers from 1 to n
*/
int totalSetBits(int n) {

	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += totalSetBitsSingleNumber(i);
	}
	return total;
}

/**
* Starting point of the program
*/
int main() {

	assert(totalSetBits(3) == 4);
	assert(totalSetBits(6) == 9);
	assert(totalSetBits(7) == 12);
	assert(totalSetBits(8) == 13);
}