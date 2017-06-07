#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleHistogram(std::vector<int>& heights) {
        
        // Create a stack to store the indices of the vector
        std::stack<int> stk;
        int area = 0;
        int maxArea = 0;
        int i = 0;
        
        // Traverse through all heights
        while(i < heights.size()) {
            
            // If stack is empty or top of the stack is smaller than the current element,
            // we can add the current index to the stack
            if(stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i);
                i++;
            }
            
            // Else remove elements from the stack till the stack becomes empty or top of the 
            // stack is less than the current element
            else {
                int top = stk.top();
                stk.pop();
                if(stk.empty()) {
                    area = heights[top] * i;
                }
                else {
                    area = heights[top] * (i - stk.top() - 1);
                }
                maxArea = std::max(maxArea, area);
            }
        }
        
        // Once we reach the end of the vector
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
            maxArea = std::max(maxArea, area);
        }
        
        return maxArea;
    }

    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        
        // Creat a matrix to store rows of histogram
        std::vector<std::vector<int>> H;
        
        // Initialize histogram
        for(int i = 0; i < matrix.size(); i++) {
            std::vector<int> hRow;
            for(int j = 0; j < matrix[i].size(); j++) {
                hRow.push_back(0);
            }
            H.push_back(hRow);
        }
        int maxArea = 0;
        
        // For each row, create a histogram, and calculate maximum area
        for(int i = 0; i < matrix.size(); i++) {
            
            // For first row, copy elements from matrix as it is
            if(i == 0) {
                for(int j = 0; j < matrix[i].size(); j++) {
                    H[i][j] = matrix[i][j] - '0';
                }
            }
            
            // For remaining rows, inherit from the upper rows
            else {
                for(int j = 0; j < matrix[i].size(); j++) {
                    if(matrix[i][j] == '1') H[i][j] = H[i - 1][j] + 1;
                    else H[i][j] = 0;
                }
            }
            
            // Calculate max area
            int area = largestRectangleHistogram(H[i]);
            maxArea = std::max(maxArea, area);
        }
        
        return maxArea;
    }
};
