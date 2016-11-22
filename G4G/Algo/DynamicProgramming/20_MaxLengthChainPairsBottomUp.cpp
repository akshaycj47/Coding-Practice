#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

/**
* Comparison function to be used in sort
* @params {const pair} a - First pair in comparison
* @params {const pair} b - Second pair in comparison
* @return {bool} Comparison value
*/
bool comparison(const std::pair<int, int>& a, const std::pair<int, int>& b) {

	return a.first < b.first;
}

/**
* Function that calculates the maximum length of chain obtained by pairs.
* This function runs a modified LIS process where we compare the second element of 
* already finalized LIS with the first element of new LIS to be constructed.
* @params {vector} - Vector of pairs (sorted)
* @return {int} Maximum length of chain obtained by pairs
*/
int maxLengthChainPairs(std::vector<std::pair<int, int>>& v) {

	if (v.size() < 2) {
		return v.size();
	}

	// Create an array to store the DP results and initialize all positions 
	// with 1
	int* L = new int[v.size()];
	for (int i = 0; i < v.size(); i++) {
		L[i] = 1;
	}

	// Start the calculations using DP
	// This is a modified variant of LIS
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].first && L[j] + 1 > L[i]) {
				L[i] = L[j] + 1;
			}
		}
	}

	// Pick up maximum of the array
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		if (max < L[i]) {
			max = L[i];
		}
	}
	return max;
}

/**
* Starting point of the program
*/
int main() {

	std::vector<std::pair<int, int>> v;
	v.push_back(std::make_pair(5, 24));
	v.push_back(std::make_pair(39, 60));
	v.push_back(std::make_pair(15, 28));
	v.push_back(std::make_pair(27, 40));
	v.push_back(std::make_pair(50, 90));
	sort(v.begin(), v.end(), comparison);
	assert(maxLengthChainPairs(v) == 3);

	std::vector<std::pair<int, int>> v2;
	v2.push_back(std::make_pair(5, 24));
	v2.push_back(std::make_pair(15, 25));
	v2.push_back(std::make_pair(27, 40));
	v2.push_back(std::make_pair(50, 60));
	std::sort(v2.begin(), v2.end(), comparison);
	assert(maxLengthChainPairs(v2) == 3);
}