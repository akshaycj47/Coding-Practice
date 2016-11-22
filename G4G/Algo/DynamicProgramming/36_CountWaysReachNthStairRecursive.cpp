#include <cassert>

/**
* Function that counts number of ways we can reach Nth stair
* @params {int} n - Number of stairs
* @return {int} Number of ways we can reach Nth stair
*/
int numWaysReachNthStair(int n) {

	if (n == 1 || n == 0) {
		return 1;
	}
	return numWaysReachNthStair(n - 1) + numWaysReachNthStair(n - 2);
}

/**
* Starting point of the program
*/
int main() {

	assert(numWaysReachNthStair(4) == 5);
	assert(numWaysReachNthStair(3) == 3);
	assert(numWaysReachNthStair(1) == 1);
}