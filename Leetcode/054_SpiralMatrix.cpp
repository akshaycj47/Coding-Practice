#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        
        // Final result
        std::vector<int> result;
        
        // Find m, n
        int m = matrix.size();
        if(m == 0) return result;
        int n = matrix[0].size();
        
        int T = 0;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        while(result.size() < m * n) {
            
            // Move right
            if(T % 4 == 0) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            
            // Move down
            else if(T % 4 == 1) {
                for(int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            
            // Move left
            else if(T % 4 == 2) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Move up
            else if(T % 4 == 3) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
            // Increment T
            T++;
        }
        
        return result;
    }
};