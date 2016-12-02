#include <cstring>
#include <iostream>

/**
 * Function which swaps two characters
 * @params {char} x - First character
 * @params {char} y - Second character
 */
void swap(char* x, char* y) {

	char temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Function which prints all the permutations of a given string
 * @params {char array} c - Given string
 * @params {int} l - Lower index of the string
 * @params {int} r - Upper index of the string
 */
void printPermutationsString(char* c, int l, int r) {

	if (l == r) {
		std::cout << c << std::endl;
	}
	else {
		for (int i = l; i <= r; i++) {
			swap(c + l, c + i);
			printPermutationsString(c, l + 1, r);
			swap(c + l, c + i);							// Backtracking
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	char c[] = "ABC";
	int n = strlen(c);
	printPermutationsString(c, 0, n - 1);

	char c2[] = "ABCD";
	int n2 = strlen(c2);
	printPermutationsString(c2, 0, n2 - 1);
}