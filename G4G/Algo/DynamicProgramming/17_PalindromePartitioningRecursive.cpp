#include <algorithm>
#include <string>
#include <cassert>

/**
* Function that checks if a given substring is a Palindrome or not
* @params {std::string} s - String which we want to check
* @params {int} x - Start index of string
* @params {int} y - End index of string
* @return {bool} true if given substring is Palindrome, false otherwise
*/
bool isPalindrome(std::string s, int lo, int hi) {

	while (lo < hi) {
		if (s[lo] != s[hi]) {
			return false;
		}
		lo++;
		hi--;
	}
	return true;
}

/**
* Function that computes minimum number of partitions required
* to make all the substrings Palindrome
* @params {std::string} s - String for which we want to calculate minimum partitions
* @params {int} x - Start index of string
* @params {int} y - End index of string
* @return {int} Minimum number of partitions required to make all
* the substrings Palindrome
*/
int minPalindromePartitioning(std::string s, int x, int y) {

	// If string is of length 1
	if (x == y) {
		return 0;
	}

	// If string is palindrome
	if (isPalindrome(s, x, y)) {
		return 0;
	}

	// Else, traverse 'i' for given length of the string to find the optimum solution
	int minPart = s.size();
	for (int i = x; i < y; i++) {
		minPart = std::min(minPart, 
						   1 + 
						   minPalindromePartitioning(s, x, i) +
						   minPalindromePartitioning(s, i + 1, y));
	}
	return minPart;
}

/**
* Starting point of the program
*/
int main() {

	std::string s1 = "ababbbabbababa";
	assert(minPalindromePartitioning(s1, 0, s1.size() - 1) == 3);
}