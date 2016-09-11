#include <cassert>

/**
* Function that computes the number of ways that k objects can be
* chosen from among n objects
* @params {int} n
* @params {int} k
* @return {int} number of ways that k objects can be chosen from
* among n objects
*/
int binomialCoefficient(int n, int k) {

	if (k == 0 || n == k) {
		return 1;
	}
	return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

/**
* Starting point of the program
*/
int main() {

	assert(binomialCoefficient(4, 2) == 6);
	assert(binomialCoefficient(5, 2) == 10);
}