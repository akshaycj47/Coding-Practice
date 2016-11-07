#include <cassert>

/**
 * Function which finds the element which occurs the maximum number of 
 * times in an array using Moore's voting algorithm. Basic idea of the 
 * algorithm is that if we cancel out each occurrence of an element e 
 * with all the other elements that are other than e, then e will exist 
 * till end if it is a majority element
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Element which occurs the maximum number of times in array
 */
int findCandidate(int* arr, int n) {

	int majIndex = 0;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[majIndex]) {
			count++;
		}
		else {
			count--;
		}
		if (count == 0) {
			majIndex = i;
			count = 1;
		}
	}
	return arr[majIndex];
}

/**
 * Function which finds the majority element in an array. A majority element
 * is an element in an array that occurs more than n / 2 times. We use Moore's
 * voting algorithm in this solution. It is a two step process, first find 
 * the element occurring the most number of times, then figure out whether 
 * that element is the majority element
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Majority element in an array
 */
int majorityElement(int* arr, int n) {

	int candidate = findCandidate(arr, n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == candidate) {
			count++;
		}
		if (count > n / 2) {
			return candidate;
		}
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(majorityElement(arr, n) == 4);

	int arr2[] = {3, 3, 4, 2, 4, 4, 2, 4};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(majorityElement(arr2, n2) == -1);
}