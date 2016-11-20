#include <cassert>

/**
 * Function which checks if one person has an acquaintance with the
 * second person. Values are based on the acquaintance matrix
 * @params {int} a - First person
 * @params {int} b - Second person
 * @return {bool} If a knows b, return true; else false
 */
bool haveAcquaintaince(int a, int b) {

	int matrix[4][4] = {{0, 0, 1, 0},
						{0, 0, 1, 0},
						{0, 0, 0, 0},
						{0, 0, 1, 0}};
	return matrix[a][b];
}

/**
 * Function which finds a celebrity (if any) in a party of n people
 * @params {int} n - Number of people in the party
 * @return {int} Index of celebrity; return -1 if celebrity not found
 */
int findCelebrity(int n) {

	// Initialize two pointers as two corners
	int a = 0;
	int b = n - 1;

	// Keep moving till both pointers don't be the same
	while (a < b) {

		// If a knows b, then a can't be celebrity. Discard a,
		// b may be celebrity
		if (haveAcquaintaince(a, b)) {
			a++;
		}

		// If a doesn't know b, then b can't be celebrity. Discard
		// b, a may be celebrity
		else {
			b--;
		}
	}

	// Check if a is actually a celebrity or not
	for (int i = 0; i < n; i++) {

		if (i != a && (haveAcquaintaince(a, i) || !haveAcquaintaince(i, a))) {
			return -1;
		}
	}
	return a;
}

/**
 * Starting point of the program
 */
int main() {

	assert(findCelebrity(4) == 2);	
}