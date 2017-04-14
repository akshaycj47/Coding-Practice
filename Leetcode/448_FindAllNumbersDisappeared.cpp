#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        
        // Final result
        std::vector<int> result;
        
        // We will use negative indexing to mark numbers that are present in the list
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i]) - 1 < nums.size() && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }
        
        // Find all indices which are positive, these are the ones missing
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};