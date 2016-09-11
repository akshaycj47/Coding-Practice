#include <cassert>
#include <algorithm>

/**
* Function that computes the maximum value of subset of val[] 
* such that sum of the weights of this subset is smaller than or equal to W. 
* @params {array} wt - Array of weights
* @params {array} v - Array of values
* @params {int} n - Number of elements remaining currently
* @params {int} W - Maximum weight remaining currently
*/
int maxValueKnapsack(int* wt, int* v, int n, int W) {

	// If maximum permissible weight is less than zero or number of elements is less
	// than 0, then we return 0
	if (n <= 0 || W <= 0) {
		return 0;
	}

	// If current weight is lower than maximum permissible weight, we can either include
	// or not inclue current weight
	if (wt[n - 1] <= W) {
		return std::max(v[n - 1] + maxValueKnapsack(wt, v, n - 1, W - wt[n - 1]),           // Include weight in knapsack
					    maxValueKnapsack(wt, v, n - 1, W)									// Not include weight in knapsack
					   );
	}

	// If current weight is higher than maximum permissible weight, we cannot include current weight
	else {
		return maxValueKnapsack(wt, v, n - 1, W);											// Not include weight in knapsack
	}
}

/**
* Starting point of the program
*/
int main() {

	int wt[] = { 10, 20, 30 };
	int v[] = { 60, 100, 120 };
	int n = sizeof(wt) / sizeof(wt[0]);
	int W = 50;
	assert(maxValueKnapsack(wt, v, n, W) == 220);

	int wt2[] = { 5, 4, 6, 3 };
	int v2[] = { 10, 40, 30, 50 };
	int n2 = sizeof(wt2) / sizeof(wt2[0]);
	int W2 = 10;
	assert(maxValueKnapsack(wt2, v2, n2, W2) == 90);
}