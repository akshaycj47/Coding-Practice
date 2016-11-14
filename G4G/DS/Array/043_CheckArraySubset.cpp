#include <unordered_map>
#include <cassert>

bool checkArraySubset(int* arr1, int n1, int* arr2, int n2) {

	// Create a map and start storing first array elements
	std::unordered_map<int, bool> m;
	for (int i = 0; i < n1; i++) {
		m[arr1[i]] = true;
	}

	// Start searching the map for elements in second array
	for (int i = 0; i < n2; i++) {
		if (m.find(arr2[i]) == m.end()) {
			return false;
		}
	}
	return true;
}

int main() {

	int arr1[] = {11, 1, 13, 21, 3, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {11, 3, 7, 1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(checkArraySubset(arr1, n1, arr2, n2) == true);

	int arr3[] = {1, 2, 3, 4, 5, 6};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	int arr4[] = {1, 2, 4};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(checkArraySubset(arr3, n3, arr4, n4) == true);

	int arr5[] = {10, 5, 2, 23, 19};
	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	int arr6[] = {19, 5, 3};
	int n6 = sizeof(arr6) / sizeof(arr6[0]);
	assert(checkArraySubset(arr5, n5, arr6, n6) == false);
}