#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        
        // Final result
        std::vector<int> result;
        
        // Initialize the result with all 1s
        for(int i = 0; i < nums.size(); i++) {
            result.push_back(1);
        }
        
        // First, left swipe, calculate product of all elements to the left
        int lProd = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result[i] = result[i] * lProd;
            lProd = lProd * nums[i];
        }
        
        // Second, right swipe, calculate product of all elements to the right
        int rProd = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--) {
            result[i] = result[i] * rProd;
            rProd = rProd * nums[i];
        }
        
        return result;
    }
};