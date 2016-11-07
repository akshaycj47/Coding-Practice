// Next Greater Element (NGE)
// http://www.geeksforgeeks.org/next-greater-element/

#include <iostream>
#include <stack>
using namespace std;

/**
 * Function that finds out the Next Greater Element (NGE) for every index
 * @params arr {array} Array for which we have to find NGE
 * @params n {int} Size of the array
 */
void nextGreaterElement(int* arr, int n) {
	stack<int> stk;

	stk.push(arr[0]);
	for(int i = 1; i < n; i++) {
		while(!stk.empty() && stk.top() < arr[i]) {
			cout << stk.top() << ": " << arr[i] << endl;
			stk.pop();
		}
		stk.push(arr[i]);
	}
	while(!stk.empty()) {
		cout << stk.top() << ": -1" << endl;
		stk.pop();
	}
}

/**
 * Starting point of the program
 */
int main() {
	int arr1[] = {4, 5, 2, 25};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	nextGreaterElement(arr1, n1);

	int arr2[] = {13, 7, 6, 12};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	nextGreaterElement(arr2, n2);
}