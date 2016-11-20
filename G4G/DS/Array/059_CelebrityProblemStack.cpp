#include <stack>
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

	// Create a stack and fill it with all the people in the party
	std::stack<int> s;
	for (int i = 0; i < n; i++) {
		s.push(i);
	}

	// Pop out two persons from stack
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();

	while (s.size() > 1) {

		// If a knows b, a can't be a celebrity. Discard a, b may be
		// a celebrity
		if (haveAcquaintaince(a, b)) {
			a = s.top();
			s.pop();
		}

		// If a doesn't know b, b can't be a celebrity. Discard b, a 
		// may be a celebrity
		else {
			b = s.top();
			s.pop();
		}
	}

	// Potential candidate, the last element in the stack
	int c = s.top();
	s.pop();

	// Last candidate was not examined, it leads to one excess comparison
	if (haveAcquaintaince(c, a)) {
		c = a;
	}
	if (haveAcquaintaince(c, b)) {
		c = b;
	}

	// Check if c is actually a celebrity or not
	for (int i = 0; i < n; i++) {

		if (i != c && (haveAcquaintaince(c, i) || !haveAcquaintaince(i, c))) {
			return -1;
		}
	}
	return c;
}

/**
 * Starting point of the program
 */
int main() {

	assert(findCelebrity(4) == 2);	
}