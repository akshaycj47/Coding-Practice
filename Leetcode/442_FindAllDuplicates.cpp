#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        
        // Final result
        std::vector<int> result;
        
        // We will find duplicates using negative indexing
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i]) - 1 < nums.size()) {
                if(nums[abs(nums[i]) - 1] > 0) {
                    nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
                }
                else {
                    result.push_back(abs(nums[i]));
                }
            }
        }
        
        // Return final result
        return result;
    }
};