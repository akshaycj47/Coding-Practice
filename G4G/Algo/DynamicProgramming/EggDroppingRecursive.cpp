#include <cassert>
#include <climits>
#include <algorithm>
#define INVALID -1

/**
* Function that computes the minimum number of trials required to 
* find the floor (critical floor) where the eggs start breaking
* @params {int} n - Number of eggs
* @params {int} k - Number of floors
* @return {int} minimum number of trials to find critical floor
*/
int eggDropping(int n, int k) {

	// If there are less than 0 eggs left, then we cannot find critical floor
	if (n < 0) {
		return INVALID;
	}

	// If there are no eggs left, and number of floors is greater than 0, then
	// we cannot find critical floor
	else if (n == 0 && k > 0) {
		return INVALID;
	}

	// If there are no floors left, we don't need to drop any eggs
	// If there is 1 floor left, we only have to drop eggs once
	else if (k == 0 || k == 1) {
		return k;
	}

	// If there is one egg left, we have to try dropping it on every floor
	// to find out the critical one
	else if (n == 1) {
		return k;
	}

	// For the remaining cases, we have to find the optimum floor that can give us the
	// result in minimum possible drops. For every floor, the egg can either break or not
	// break after dropping. In some cases, egg breaking could be good; and in some cases
	// egg not breaking could be good. Either ways, we have to find the optimum floor where 
	// even in the worst case, we find minimum number of drops
	else {
		int minDrops = INT_MAX;
		for (int f = 1; f <= k; f++) {
			int curr = std::max(eggDropping(n - 1, f - 1),				// when egg breaks
								eggDropping(n, k - f)					// when egg does not break
								);
			minDrops = std::min(minDrops, curr);
		}
		return 1 + minDrops;
	}
}

/**
* Starting point of the program
*/
int main() {

	assert(eggDropping(2, 10) == 4);
	assert(eggDropping(2, 18) == 6);
	assert(eggDropping(0, 5) == INVALID);
	assert(eggDropping(-1, 0) == INVALID);
	assert(eggDropping(1, 10000) == 10000);
	assert(eggDropping(56, 1) == 1);
	//assert(eggDropping(2, 36) == 8);
}