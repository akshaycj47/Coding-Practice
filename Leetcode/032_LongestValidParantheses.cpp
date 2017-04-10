#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        
        int longest = 0;
        std::stack<int> stk;
        // Start filling indices in stack
        for(int i = 0; i < s.size(); i++) {
            
            // If current character is opening paranthesis
            if(s[i] == '(') {
                stk.push(i);
            }
            
            // If current characters is closing paranthesis
            else {
                // If we find matching parantheses
                if(!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                }
                
                // If not matching pair is found, then enter the index in the stack
                else {
                    stk.push(i);
                }
            }
        }
        
        // If stack is empty, then entire string is the longest valid parantheses
        if(stk.empty()) {
            longest = s.size();
        }
        // Else, after the scan is done, only the characters which were not matched will be 
        // contained in the stack. The space between these unmatched characters was valid parantheses
        else {
            int a = s.size();
            int b = 0;
            while(!stk.empty()) {
                b = stk.top();
                stk.pop();
                longest = std::max(longest, a - b - 1);
                a = b;
            }
            longest = std::max(longest, a);
        }
        
        return longest;
    }
};