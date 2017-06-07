#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        
        // Create a stack to store the indices
        std::stack<int> stk;
        int area = 0;
        int maxArea = 0;
        int i = 0;
        
        // Traverse through all heights
        while(i < heights.size()) {
            
            // Add current index to the stack when current element is greater than top of
            // the stack, or the stack is empty
            if(stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i);
                i++;
            }
            
            // Else, try removing elements from the stack one by one till no elements remain in the
            // stack or stack top is lesser than current element
            else {
                int top = stk.top();
                stk.pop();
                if(stk.empty()) {
                    area = heights[top] * i;
                }
                else {
                    area = heights[top] * (i - stk.top() - 1);
                }
                maxArea = std::max(area, maxArea);
            }
        }
        
        // Once we reach the end of the array
        // Keep popping remaining elements till the stack becomes empty, and calculate the area
        while(!stk.empty()) {
            int top = stk.top();
            stk.pop();
            if(stk.empty()) {
                area = heights[top] * i;
            }
            else {
                area = heights[top] * (i - stk.top() - 1);
            }
            maxArea = std::max(area, maxArea);
        }
        
        return maxArea;
    }
};
