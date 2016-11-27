#include <cassert>

int numPossibleTriangles(int* arr, int n) {

}

int main() {

	int arr[] = {4, 6, 3, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(numPossibleTriangles(arr, n) == 3);

	int arr2[] = {10, 21, 22, 100, 101, 200, 300};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(numPossibleTriangles(arr2, n2) == 6);
}