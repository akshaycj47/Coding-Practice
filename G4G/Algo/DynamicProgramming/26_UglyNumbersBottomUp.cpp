#include <algorithm>
#include <cassert>

/**
* Function to find the minimum of three numbers
* @params {int} x - First number
* @params {int} y - Second number
* @params {int} z - Third number
* @return {int} Minimum of three numbers
*/
int minThree(int x, int y, int z) {
	
	return std::min(x, std::min(y, z));
}

/**
* Function that returns nth ugly number
* Ugly numbers are numbers whose only prime factors are 2, 3, or 5
* Ugly numbers can be constructed by multiplying either 2, 3, or 5 
* to a smaller ugly number. They key is to maintain the order of ugly
* numbers
* @params {int} n
* @return {int} nth ugly number
*/
int nthUglyNumber(int n) {

	int* ugly = new int[n + 1];
	ugly[1] = 1;
	int i2 = 1;
	int i3 = 1;
	int i5 = 1;
	for (int i = 2; i <= n; i++) {
		ugly[i] = minThree(ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5);
		if (ugly[i] == ugly[i2] * 2) {
			i2++;
		}
		if (ugly[i] == ugly[i3] * 3) {
			i3++;
		}
		if (ugly[i] == ugly[i5] * 5) {
			i5++;
		}
	}
	return ugly[n];
}

/**
* Starting point of the program
*/
int main() {

	assert(nthUglyNumber(150) == 5832);
	assert(nthUglyNumber(200) == 16200);
	assert(nthUglyNumber(56) == 320);
	assert(nthUglyNumber(91) == 1200);
}