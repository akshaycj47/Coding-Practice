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
 * @params {int} n - Length of the string
 */
void printPermutationsString(char* c, int n) {

	for (int i = 0; i < n; i++) {

		// Initial swap
		swap(c + 0, c + i);

		// For all the remaining elements except fixed element
		for (int j = 0; j < n - 1; j++) {

			// Shifting for loop
			for (int k = 1; k < n - 1; k++) {
				swap(c + k, c + k + 1);					// Shifting 1st element one by one till it reaches the end
				std::cout << c << std::endl;
			}
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	char c[] = "ABC";
	int n = strlen(c);
	printPermutationsString(c, n);

	char c2[] = "ABCD";
	int n2 = strlen(c2);
	printPermutationsString(c2, n2);
}