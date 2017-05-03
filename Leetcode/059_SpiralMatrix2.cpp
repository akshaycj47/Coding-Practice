#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        
        // Final result
        std::vector<std::vector<int>> result;
        
        // Initialize the result
        for(int i = 0; i < n; i++) {
            std::vector<int> row;
            for(int j = 0; j < n; j++) {
                row.push_back(0);
            }
            result.push_back(row);
        }
        
        // Start filling the result matrix
        int T = 0;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int x = 1;
        while(x <= n * n) {
            
            // Move right
            if(T % 4 == 0) {
                for(int i = left; i <= right; i++) {
                    result[top][i] = x;
                    x++;
                }
                top++;
            }
            
            // Move down
            else if(T % 4 == 1) {
                for(int i = top; i <= bottom; i++) {
                    result[i][right] = x;
                    x++;
                }
                right--;
            }
            
            // Move left
            else if(T % 4 == 2) {
                for(int i = right; i >= left; i--) {
                    result[bottom][i] = x;
                    x++;
                }
                bottom--;
            }
            
            // Move up
            else if(T % 4 == 3) {
                for(int i = bottom; i >= top; i--) {
                    result[i][left] = x;
                    x++;
                }
                left++;
            }
            
            // Increment T
            T++;
        }
        
        return result;
    }
};