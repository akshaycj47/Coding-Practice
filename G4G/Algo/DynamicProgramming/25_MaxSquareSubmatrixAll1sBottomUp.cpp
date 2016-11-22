#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>

/**
* Function that returns minimum of three numbers
* @params {int} x - First number
* @params {int} y - Second number
* @params {int} z - Third number
* @return {int} Minimum of three numbers
*/
int minThree(int x, int y, int z) {

	return std::min(x, std::min(y, z));
}

/**
* Function that finds out a maximum size square sub-matrix with all
* 1s, given a binary matrix
* @params {matrix} M - Given binary matrix
* @params {int} r - Number of rows in the matrix
* @params {int} c - Number of columns in the matrix
* @return {int} Size of the maximum size square sub-matrix with all 1s
*/
int maxSquareSubmatrixAllOnes(std::vector<std::vector<int>>& M, int r, int c) {

	// Construct a matrix to store DP values
	int** S = new int*[r];
	for (int i = 0; i < r; i++) {
		S[i] = new int[c];
	}

	// Copy first row and first column as it is from M[][] to S[][]
	for (int i = 0; i < r; i++) {
		S[i][0] = M[i][0];
	}
	for (int j = 0; j < c; j++) {
		S[0][j] = M[0][j];
	}

	// Start computing using DP
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {

			if (M[i][j] == 1) {
				S[i][j] = minThree(S[i - 1][j], S[i][j - 1], S[i - 1][j - 1]) + 1;
			}
			else {
				S[i][j] = 0;
			}
		}
	}

	// Find the maximum entry in S[r][c]
	int maxSize = INT_MIN;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			maxSize = std::max(maxSize, S[i][j]);
		}
	}
	return maxSize;
}

/**
* Starting point of the program
*/
int main() {

	std::vector<std::vector<int>> M = { { 0, 1, 1, 0, 1 },
										{ 1, 1, 0, 1, 0 },
										{ 0, 1, 1, 1, 0 },
										{ 1, 1, 1, 1, 0 },
										{ 1, 1, 1, 1, 1 },
										{ 0, 0, 0, 0, 0 }
									  };
	assert(maxSquareSubmatrixAllOnes(M, M.size(), M[0].size()) == 3);
}