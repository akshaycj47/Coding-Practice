#include <limits>
#include <cmath>
#include <algorithm>
#include <cassert>

/**
* Data structure for point
* @params {int} x - x coordinate
* @params {int} y - y coordinate
*/
struct Point {
	int x;
	int y;
};

/**
* Function which calculates distance between two points
* @params {Point} p1 - First point
* @params {Point} p2 - Second point
* @return {float} Distance between two points
*/
float findDistance(Point p1, Point p2) {

	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/**
* Function which calculates minimum distance between a set
* of points
* @params {array} arr - Given array consisting of points
* @params {int} n - Number of elements in array
* @return {float} Minimum distance between set of points
*/
float closestPairPoints(Point* arr, int n) {

	if (n < 2) {
		return 0.0;
	}
	float minDistance = std::numeric_limits<float>::max();

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			minDistance = std::min(minDistance, findDistance(arr[j], arr[i]));
		}
	}
	return minDistance;
}

/**
* Starting point of the program
*/
int main() {

	Point arr[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(closestPairPoints(arr, n) - 1.41421 < 1e-5);
}