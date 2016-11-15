#include <cassert>

/**
 * Function which finds a fixed point in the array. Fixed point is a point
 * where index and arr[index] are the same
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Fixed point in an array
 */
int fixedPoint(int* arr, int n) {

	int lo = 0;
	int hi = n - 1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (mid == arr[mid]) {
			return mid;
		}
		else if (mid < arr[mid]) {
			hi = mid - 1;
		}
		else if (mid > arr[mid]) {
			lo = mid + 1;
		}
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {-10, -5, 0, 3, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(fixedPoint(arr, n) == 3);

	int arr2[] = {0, 2, 5, 8, 17};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(fixedPoint(arr2, n2) == 0);

	int arr3[] = {-10, -5, 3, 4, 7, 9};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(fixedPoint(arr3, n3) == -1);
}