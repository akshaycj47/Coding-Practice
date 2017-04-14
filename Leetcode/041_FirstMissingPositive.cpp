#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int segregate(std::vector<int>& nums) {
        
        int i = 0; 
        int j = nums.size() - 1;
        
        while(i <= j) {
            
            while(i <= j && nums[i] > 0) {
                i++;
            }
            while(i <= j && nums[j] <= 0) {
                j--;
            }
            if(i < j && nums[i] <= 0 && nums[j] > 0) {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return i;
    }

    int firstMissing(std::vector<int>& nums, int size) {
        
        // Use negative indexing to store the numbers
        // -1 is used since indexing starts from 0 instead of 1
        for(int i = 0; i < size; i++) {
            if(abs(nums[i]) - 1 < size && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }
        
        // Find the first non-negative number and return the index (+ 1)
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }

    int firstMissingPositive(std::vector<int>& nums) {
        
        // First segregate the numbers into positive and non-positive
        int start = segregate(nums);
        
        // Now find first missing number only from the positive numbers
        return firstMissing(nums, start);
    }
};