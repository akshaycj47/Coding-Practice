#include <vector>

class Solution {
public:
    int searchStartIndex(std::vector<int>& nums, int target, int lo, int hi) {
        
        int index = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            // If mid element is equal to target, select index and continue searching to the left
            if(target <= nums[mid]) {
                if(target == nums[mid]) index = mid;
                hi = mid - 1;
            }
            // If mid element is lesser than target, search on the right
            if(target > nums[mid]) {
                lo = mid + 1;
            }
        }
        
        return index;
    }
    
    int searchEndIndex(std::vector<int>& nums, int target, int lo, int hi) {
        
        int index = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            // If mid element is equal to target, select index and continue searching to the right
            if(target >= nums[mid]) {
                if(target == nums[mid]) index = mid;
                lo = mid + 1;
            }
            // If mid element is greater than target, search on the left
            if(target < nums[mid]) {
                hi = mid - 1;
            }
        }
        
        return index;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        
        std::vector<int> result;
        result.push_back(searchStartIndex(nums, target, 0, nums.size() - 1));
        result.push_back(searchEndIndex(nums, target, 0, nums.size() - 1));
        return result;
    }
};