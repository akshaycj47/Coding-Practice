#include <vector>
#include <map>

class Solution {
public:
    // Check if input is valid or not. Input is valid if all characters
    // lie between 2 and 9
    bool isValidInput(string digits) {
        
        if (digits.size() == 0) return false;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] < '2' || digits[i] > '9') {
                return false;
            }
        }
        return true;
    }
    
    // Utility function to compute letter combinations
    void letterCombinationsUtil(std::string s, std::string m[10], std::vector<string>& ans, std::string result) {
        
        if (s.size() > 1) {
            
            char curr = s[0] - '0';
            for(int i = 0; i < m[curr].size(); i++) {
                letterCombinationsUtil(s.substr(1), m, ans, result + m[curr][i]);
            }
        }
        else if (s.size() == 1) {
            
            char curr = s[0] - '0';
            for (int i = 0; i < m[curr].size(); i++) {
                ans.push_back(result + m[curr][i]);
            }
        }
    }

    // Main letter combination function
    vector<string> letterCombinations(string digits) {
        
        std::vector<string> ans;
        if (!isValidInput(digits)) return ans;
        
        std::string m[10] = {};
        m[0] = "";
        m[1] = "";
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        letterCombinationsUtil(digits, m, ans, "");
        return ans;
    }
};