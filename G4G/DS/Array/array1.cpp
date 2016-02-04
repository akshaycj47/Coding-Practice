// Given an array A[] and a number x, check for pair in A[] with sum as x
// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

#include <iostream>
#include <map>
using namespace std;

void printPair(int* arr, int n, int sum) {
	map<int, bool> m;

	for(int i = 0; i < n; i++) {
		if(m.find(sum - arr[i]) != m.end()) {
			cout << "First number: " << sum - arr[i] << endl;
			cout << "Second number: " << arr[i] << endl;
		}
		m[arr[i]] = true;
	}
}

int main() {
	int arr[] = {1, 5, 9, 4, 2, 7, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 12;
	printPair(arr, n, sum);
}