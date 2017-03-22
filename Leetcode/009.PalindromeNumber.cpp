#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        // Discard negative numbers
        if (x < 0) {
            return false;
        }
        
        // Count number of digits
        int temp = x;
        int digits = 0;
        while (temp != 0) {
            temp = temp / 10;
            digits++;
        }
        
        // Now check if the number is Palindrome or not
        int divisor = pow(10, digits - 1);
        temp = x;
        while (divisor > 0) {
            int lhs = (temp / divisor) % 10;
            int rhs = temp % 10;
            if (lhs != rhs) {
                return false;
            }
            temp = temp / 10;
            divisor = divisor / 100;
        }
        return true;
    }
};