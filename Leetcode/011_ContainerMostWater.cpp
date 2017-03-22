#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * std::min(height[i], height[j]);
            maxArea = std::max(maxArea, area);
            if (height[i] > height[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return maxArea;
    }
};