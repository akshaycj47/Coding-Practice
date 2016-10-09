#include <algorithm>
#include <climits>
#include <cassert>

int main() {

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(minNumberJumps(arr, n, 0) == 3);
}