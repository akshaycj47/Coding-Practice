#include <vector>
#include <algorithm>
#include <iostream>

/**
 * Pair Sum Class
 * @member {int} v1 - First element
 * @member {int} v2 - Second element
 * @member {int} sum - Sum of pair
 */
class pairSum {
public:
	int v1;
	int v2;
	int sum;
	pairSum(int v1, int v2, int sum) {
		this->v1 = v1;
		this->v2 = v2;
		this->sum = sum;
	}
};

/**
 * Comparison function to be used with std::sort
 * @params {pairSum} a - First pair
 * @params {pairSum} b - Second pair
 */
bool comparison(const pairSum& a, const pairSum& b) {

	return a.sum < b.sum;
}

/**
 * Function which checks if there are any common elements between
 * two pairs
 * @params {pairSum} a - First pair
 * @params {pairSum} b - Second pair
 * @return {bool} If there are common elements, return false; else
 * return true
 */
bool noCommon(const pairSum&a, const pairSum& b) {

	if (a.v1 == b.v1 || a.v1 == b.v2 || a.v2 == b.v1 || a.v2 == b.v2) {
		return false;
	}
	return true;
}

/**
 * Function which finds four elements such that their sum is equal 
 * to the given value
 * @params {vector} v - List of elements
 * @params {int} total - Given value which is equal to sum of 4 elements
 */
void find4ElementsGivenSum(std::vector<int>& v, int total) {

	// Create an auxiliary array to store the sum of all possible 
	// pairs in the list
	std::vector<pairSum> aux;
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			aux.push_back(pairSum(v[i], v[j], v[i] + v[j])); 
		}
	}

	// Sort the auxiliary array based on the sum
	std::sort(aux.begin(), aux.end(), comparison);

	// Find two sums in aux array where the sum is equal to the given value
	int i = 0; 
	int j = aux.size() - 1;
	while (i < aux.size() && j >= 0) {
		if (aux[i].sum + aux[j].sum == total && noCommon(aux[i], aux[j])) {
			std::cout << "Four elements: " << aux[i].v1 << ", " << aux[i].v2 << ", " << aux[j].v1 << ", " << aux[j].v2 << std::endl;
			return;
		}
		else if (aux[i].sum + aux[j].sum < total) {
			i++;
		}
		else if (aux[i].sum + aux[j].sum > total) {
			j--;
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	std::vector<int> v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(9);
	v.push_back(7);
	v.push_back(8);
	find4ElementsGivenSum(v, 23);

	std::vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(1);
	v2.push_back(2);
	find4ElementsGivenSum(v2, 91);
}