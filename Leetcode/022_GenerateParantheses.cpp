#include <string>

class Solution {
public:
    // Utility function to generate paranthesis
    void generateParanthesisUtil(vector<std::string>& result, int numOpen, int numClose, int n, std::string ans, char curr) {
        
        if(numOpen > n) {
            return;
        }
        if(numClose > numOpen) {
            return;
        }
        
        ans = ans + curr;
        if(numOpen == n && numClose == n) {
            result.push_back(ans);
        }
        else {
            generateParanthesisUtil(result, numOpen + 1, numClose, n, ans, '(');
            generateParanthesisUtil(result, numOpen, numClose + 1, n, ans, ')');
        }
    }
    
    // Main generate paranthesis function
    vector<std::string> generateParenthesis(int n) {
        
        vector<std::string> result;
        if(n == 0) {
            return result;
        }
        generateParanthesisUtil(result, 1, 0, n, "", '(');
        return result;
    }
};