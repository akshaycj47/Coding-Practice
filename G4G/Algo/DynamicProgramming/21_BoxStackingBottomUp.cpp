#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

// Data structure for the box
class Box {
public:
	int h;									// Height of the box
	int l;									// Length of the box
	int w;									// Width of the box

	// Parameterized constructor for the box
	Box (int _h, int _l, int _w) {
		this->h = _h;
		this->l = _l;
		this->w = _w;
	}

	// Return base area of the box
	int getBaseArea() {
		return this->l * this->w;
	}
};

/**
* Function that computes all rotation combinations for a given box
* We need all rotation combinations because boxes can be rotated and reused in this problem
* @params {std::vector} v - Vector of boxes for which we want to find all rotation combinations
*/
void findAllRotationsOfBox(std::vector<Box>& v) {

	int initialCount = v.size();
	for (int i = 0; i < initialCount; i++) {
		Box b1(v[i].l, v[i].h, v[i].w);
		v.push_back(b1);
		Box b2(v[i].w, v[i].h, v[i].l);
		v.push_back(b2);
	}
}

/**
* Comparison operator for std::sort
* Two boxes are sorted in descending order according to the base area
* We need all rotation combinations because boxes can be rotated and reused in this problem
* @params {Box} b1 - First box to be compared
* @params {Box} b2 - Second box to be compared
*/
bool comparison(Box& b1, Box& b2) {

	return b1.getBaseArea() > b2.getBaseArea();
}

/**
* Function that computes the maximum height that can be obtained by stacking boxes 
* such that base dimensions of lower box are larger than base dimensions of the higher box
* Boxes can be rotated and reused
* @params {std::vector} v - Vector of boxes for which we want to compute max stack height
* @return {int} Maximum height that can be obtained by stacking boxes
*/
int maxBoxStackHeight(std::vector<Box>& v) {

	findAllRotationsOfBox(v);
	std::sort(v.begin(), v.end(), comparison);

	// Create an array to store the LIS values and initialize it with individual height
	int* L = new int[v.size()];
	for (int i = 0; i < v.size(); i++) {
		L[i] = v[i].h;
	}

	// Start calculating the LIS such that lower box base dimensiont are larger than
	// upper box base dimensions
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {

			if (v[j].w > v[i].w && v[j].l > v[i].l && L[j] + v[i].h > L[i]) {
				L[i] = L[j] + v[i].h;
			} 
		}
	}

	// Compute the maximum height of stack
	int maxHeight = 0;
	for (int i = 0; i < v.size(); i++) {
		maxHeight = std::max(maxHeight, L[i]);
	}
	return maxHeight;
}

/**
* Starting point of the program
*/
int main() {

	std::vector<Box> v;
	Box b1(4, 6, 7);
	v.push_back(b1);
	Box b2(1, 2, 3);
	v.push_back(b2);
	Box b3(4, 5, 6);
	v.push_back(b3);
	Box b4(10, 12, 32);
	v.push_back(b4);

	assert(maxBoxStackHeight(v) == 60);
}