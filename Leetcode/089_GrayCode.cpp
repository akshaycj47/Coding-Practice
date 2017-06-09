#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        
        // Create a vector to store the result
        std::vector<int> result;
  
        // Add intial element
        result.push_back(0);

        // Run a loop to keep update the result vector
        for(int i = 0; i < n; i++) {
            
            // Flip the result vector, and add a mask to the second half elements
            int currSize = result.size();
            for(int j = currSize - 1; j >= 0; j--) {
                result.push_back(result[j] + currSize);
            }
        }
        
        return result;
    }
};
