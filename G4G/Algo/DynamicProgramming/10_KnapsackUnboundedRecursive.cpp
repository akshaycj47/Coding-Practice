#include <cassert>
#include <algorithm>

/**
* Function that computes the maximum value of subset of val[] 
* such that sum of the weights of this subset is smaller than or equal to W. 
* In this problem we can use weights unlimited number of times
* @params {array} wt - Array of weights
* @params {array} v - Array of values
* @params {int} n - Number of elements remaining currently
* @params {int} W - Maximum weight remaining currently
*/
int maxValueKnapsack(int* wt, int* v, int n, int W) {

	// If number of elements is 0 or maximum permissible weight is 0,
	// we return 0
	if (n <= 0 || W <= 0) {
		return 0;
	}

	// If current weight is less or equal to maximum permissible weight, 
	// we can either include it in the solution or not include it
	if (wt[n - 1] <= W) {
		return std::max(v[n - 1] + maxValueKnapsack(wt, v, n, W - wt[n - 1]),       // Include
			            maxValueKnapsack(wt, v, n - 1, W)							// Don't include
						);
	}
	
	// If current weight is more than maximum permissible weight, 
	// we cannot include it in the solution
	else {
		return maxValueKnapsack(wt, v, n - 1, W);
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
	assert(maxValueKnapsack(wt, v, n, W) == 300);

	int wt2[] = { 5, 4, 6, 3 };
	int v2[] = { 10, 40, 30, 50 };
	int n2 = sizeof(wt2) / sizeof(wt2[0]);
	int W2 = 10;
	assert(maxValueKnapsack(wt2, v2, n2, W2) == 150);
}