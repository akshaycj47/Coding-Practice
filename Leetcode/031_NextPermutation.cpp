#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findFirstIndex(std::vector<int>& nums) {
        
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                return i - 1;
            }
        }
        return -1;
    }
    
    int findSecondIndex(std::vector<int>& nums, int firstIdx) {
        
        int firstNum = nums[firstIdx];
        int secondNum = INT_MAX;
        int secondIdx = -1;
        
        for(int i = firstIdx + 1; i < nums.size(); i++) {
            if(nums[i] > firstNum && nums[i] < secondNum) {
                secondNum = nums[i];
                secondIdx = i;
            }
        }
        return secondIdx;
    }
    
    void swapFirstSecondIndex(std::vector<int>& nums, int firstIdx, int secondIdx) {
        
        int temp = nums[firstIdx];
        nums[firstIdx] = nums[secondIdx];
        nums[secondIdx] = temp;
    }
    
    void nextPermutation(std::vector<int>& nums) {
        
        // Find first and second index
        int firstIdx = findFirstIndex(nums);
        if(firstIdx == -1) {
            std::sort(nums.begin(), nums.end());
            return;
        }
        int secondIdx = findSecondIndex(nums, firstIdx);
        
        // Swap elements at first and second index
        swapFirstSecondIndex(nums, firstIdx, secondIdx);
        
        // Sort all remaining elements after original first index
        std::sort(nums.begin() + firstIdx + 1, nums.end());
    }
};