class Solution {
public:
    int trap(std::vector<int>& height) {
        
        // Base case
        if(height.size() <= 1) {
            return 0;
        }
        
        int n = height.size();
        int total = 0;
        int left = 0;
        int right = n - 1;
        int maxLeft = 0;
        int maxRight = 0;
        
        while(left <= right) {
            
            if(height[left] <= height[right]) {
                if(height[left] >= maxLeft) maxLeft = height[left];
                else total = total + maxLeft - height[left];
                left++;
            }
            else {
                if(height[right] >= maxRight) maxRight = height[right];
                else total = total + maxRight - height[right];
                right--;
            }
        }
        
        return total;
    }
};