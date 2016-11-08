#include <vector>
#include <cassert>

/**
 * Function which finds leader elements in an array. An element is a 
 * leader when it is greater than all the elements to its right
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @params {vector} result - Vector to store the result
 */
void findLeaders(int* arr, int n, std::vector<int>& result) {

	if (n < 0) {
		return;
	}
	result.push_back(arr[n - 1]);
	int max = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > max) {
			result.push_back(arr[i]);
			max = arr[i];
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> result;
	std::vector<int> actual;
	actual.push_back(2);
	actual.push_back(5);
	actual.push_back(17);
	findLeaders(arr, n, result);
	for(int i = 0; i < n; i++) {
		assert(result[i] == actual[i]);
	}
}