#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        
        // Final result, initialize as a first step
        std::vector<int> result(digits.size() + 1, 0);
        
        // Reverse digits for ease of calculation
        std::reverse(digits.begin(), digits.end());
        
        // Start calculation
        int carry = 1;
        int pos;
        for(pos = 0; pos < digits.size(); pos++) {
            int sum = digits[pos] + carry;
            carry = sum / 10;
            result[pos] = sum % 10;
        }
        if(carry) result[pos] = carry;
        
        // Remove all preceding 0s
        while(result.size() > 1 && result[result.size() - 1] == 0) {
            result.pop_back();
        }
        
        // Reverse digits to get back original
        std::reverse(result.begin(), result.end());
        std::reverse(digits.begin(), digits.end());
        
        
        
        return result;
    }
};