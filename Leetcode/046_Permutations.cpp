#include <vector>
#include <algorithm>

class Solution {
public:
    void permuteUtil(std::vector<int>& nums, int l, int r, std::vector<std::vector<int>>& result) {
        
        if(l == r) {
            result.push_back(nums);
        }
        
        else {
            for(int i = l; i <= r; i++) {
                std::swap(nums[l], nums[i]);
                permuteUtil(nums, l + 1, r, result);
                std::swap(nums[l], nums[i]);                    // Backtracking
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        
        // Final result
        std::vector<std::vector<int>> result;
        
        // Find all permutations using recursion
        permuteUtil(nums, 0, nums.size() - 1, result);
        
        return result;
    }
};