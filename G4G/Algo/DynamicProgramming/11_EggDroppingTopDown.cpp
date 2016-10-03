#include <iostream>
#include <cassert>
#include <climits>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int eggDrop(int n, int k);
int eggDropUtil(int n, int k, unordered_map<string, int>& hmap);
string getKey(int a, int b);

int main() {
	int n = 2, k = 10;
	cout << eggDrop(n, k) << endl;
	return 0;
}

int eggDrop(int n, int k) {
	unordered_map<string, int> hmap;
	return eggDropUtil(n, k, hmap);
}

int eggDropUtil(int n, int k, unordered_map<string, int>& hmap) {
	// fail case: If no eggs given and non-zero floors, cannot compute
	if (n < 0 || (n == 0 && k > 0)) return -1;

	// If only one egg, need linear scan, k trials
	if (n == 1) return k;

	// If zero/one floor, need zero/one trial
	if (k == 0 || k == 1) return k;

	if (!hmap.count(getKey(n, k))) {
		int minTrial = INT_MAX;
		for (int i = 1; i <= k; i++) {
			if (!hmap.count(getKey(n - 1, i - 1))) {
				hmap[getKey(n - 1, i - 1)] = eggDropUtil(n - 1, i - 1, hmap);
			}

			if (!hmap.count(getKey(n, k - i))) {
				hmap[getKey(n, k - i)] = eggDropUtil(n, k - i, hmap);
			}

			cout << getKey(n - 1, i - 1) << ": " << hmap[getKey(n - 1, i - 1)] << endl;
			cout << getKey(n, k - i) << ": " << hmap[getKey(n, k - i)] << endl;
			int res = max(hmap[getKey(n - 1, i - 1)], hmap[getKey(n, k - i)]);
			minTrial = min(minTrial, res);
		}

		hmap[getKey(n, k)] = 1 + minTrial;
	}

	return hmap[getKey(n, k)];
}

string getKey(int a, int b) {
	return (to_string(a) + to_string(b));
}