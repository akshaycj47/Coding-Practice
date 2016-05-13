// Program to perform binary addition on two numbers represented by arrays
// CLRS page 22

#include <iostream>
#include <cassert>
using namespace std;

/**
 * Function which performs binary addition on two numbers represented by arrays
 * @params {array} a - First number represented by array
 * @params {array} b - Second number represented by array
 * @params {int} n - Size of the array
 * @params {array} c - Result array which stores the binary addition
 */
void binaryAddition(int* a, int* b, int n, int* c) {

	int carry = 0;
	for(int i = n - 1; i >= 0; i--) {
		int j = i + 1;
		if(a[i] + b[i] + carry == 0) {
			carry = 0;
			c[j] = 0;
		}
		else if(a[i] + b[i] + carry == 1) {
			carry = 0;
			c[j] = 1;
		}
		else if(a[i] + b[i] + carry == 2) {
			carry = 1;
			c[j] = 0;
		}
		else {
			carry = 1; 
			c[j] = 1;
		}
	}
	c[0] = carry;
}

/**
 * Starting point of the program
 */
int main() {

	int a[] = {1, 1, 1, 1, 1, 0};
	int b[] = {1, 0, 1, 0, 1, 1};
	int n = sizeof(a) / sizeof(a[0]);
	int* c = new int[n + 1];
	int res[] = {1, 1, 0, 1, 0, 0, 1};
	binaryAddition(a, b, n, c);
	for (int i = 0; i < n + 1; i++) {
		assert(c[i] == res[i]);
	}

	int a2[] = {1, 0, 1, 1, 1, 0, 0, 1};
	int b2[] = {1, 0, 1, 0, 0, 0, 1, 0};
	int n2 = sizeof(a2) / sizeof(a2[0]);
	int* c2 = new int[n2 + 1];
	int res2[] = {1, 0, 1, 0, 1, 1, 0, 1, 1};
	binaryAddition(a2, b2, n2, c2);
	for (int i = 0; i < n2 + 1; i++) {
		assert(c2[i] == res2[i]);
	}	
}