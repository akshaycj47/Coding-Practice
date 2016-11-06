#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

/**
* Data structure for point
* @params {int} x - x coordinate
* @params {int} y - y coordinate
* @constructor Point
*/
class Point {
public:
	int x;
	int y;
	Point(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
};

/**
* Comparison operator for std::sort
* Two points are sorted in ascending order according to their x-coordinate
* @params {Point} p1 - First point to be compared
* @params {Point} p2 - Second point to be compared
*/
bool comparisonX(Point& p1, Point& p2) {

	return p1.x < p2.x;
}

/**
* Comparison operator for std::sort
* Two points are sorted in ascending order according to their y-coordinate
* @params {Point} p1 - First point to be compared
* @params {Point} p2 - Second point to be compared
*/
bool comparisonY(Point& p1, Point& p2) {

	return p1.y < p2.y;
}

void printVector(std::vector<Point>& v) {

	for (int i = 0; i < v.size(); i++) {
		std::cout << "(" << v[i].x << ", " << v[i].y << "), ";
	}
	std::cout << std::endl;
}

/**
* Function which calculates distance between two points
* @params {Point} p1 - First point
* @params {Point} p2 - Second point
* @return {float} Distance between two points
*/
float findDistance(Point p1, Point p2) {

	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float bruteForceMinDist(std::vector<Point>& v) {

	if (v.size() < 2) {
		return 0.0;
	}
	std::sort(v.begin(), v.end(), comparisonY);

	float minDistance = std::numeric_limits<float>::max();
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			minDistance = std::min(minDistance, findDistance(v[j], v[i]));
		}
	}
	return minDistance;
}

float closestPairPoints(std::vector<Point>& v) {

	if (v.size() < 2) {
		return 0.0;
	}
	int mid = v.size() / 2;
	std::vector<Point> vL;
	std::vector<Point> vR;

	for (int i = 0; i < mid; i++) {
		vL.push_back(v[i]);
	}
	for (int i = mid; i < v.size(); i++) {
		vR.push_back(v[i]);
	}

	float dL = closestPairPoints(vL);
	float dR = closestPairPoints(vR);
	float d = std::min(dL, dR);

	std::vector<Point> vS;
	for (int i = 0; i < v.size(); i++) {
		if (abs(v[i].x - v[mid].x) < d) {
			vS.push_back(v[i]);
		}
	}
	return std::min(d, bruteForceMinDist(vS));
}

/**
* Function which calculates minimum distance between a set
* of points
* @params {vector} v - Given list consisting of points
* @return {float} Minimum distance between set of points
*/
float closestPairPointsWrapper(std::vector<Point>& v) {

	if (v.size() < 2) {
		return 0.0;
	}
	std::sort(v.begin(), v.end(), comparisonX);
	return closestPairPoints(v);
}

/**
* Starting point of the program
*/
int main() {

	std::vector<Point> v;
	Point p1(2, 3);
	v.push_back(p1);
	Point p2(12, 30);
	v.push_back(p2);
	Point p3(40, 50);
	v.push_back(p3);
	Point p4(5, 1);
	v.push_back(p4);
	Point p5(12, 10);
	v.push_back(p5);
	Point p6(3, 4);
	v.push_back(p6);
	std::cout << closestPairPointsWrapper(v) << std::endl;

	//Point arr[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	//int n = sizeof(arr) / sizeof(arr[0]);
	//closestPairPoints(arr, n);
	//assert(closestPairPoints(arr, n) - 1.41421 < 1e-5);
}