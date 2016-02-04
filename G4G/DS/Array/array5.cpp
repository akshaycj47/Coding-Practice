// Find floor and ceil in a sorted array (on hold)

#include <iostream>
using namespace std;

int findFloor(int* arr, int n, search) {
	int lo = 0;
	int hi = n - 1;

	if(search < arr[lo]) {
		return -1;
	}
	if(search > arr[hi]) {
		return hi;
	}

	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == search) {
			return mid;
		}
		else if(arr[mid] > search) {

		}
	}
}

void findFloorCeil(int* arr, int n, search) {

}

int main() {
	int arr[] = {1, 2, 8, 10, 10, 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	int search = 5;
	findFloorCeil(arr, n, search);
}