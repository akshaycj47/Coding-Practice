#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        
        // First transpose the matrix
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Swap columns one by one (for every row)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};