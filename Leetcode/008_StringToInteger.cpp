#include <climits>

class Solution {
public:
    int myAtoi(string str) {
        
        bool isPositive = true;
        int num = 0;
        int digits = 0;
        int i = 0;
        while (i < str.size() && str[i] == ' ') {
            i++;
        }
        
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-') isPositive = false;
            i++;
        }
        
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int curr = str[i] - '0';
            if (isPositive && (INT_MAX - curr <= num * 10 || digits == 10)) return INT_MAX;
            if (!isPositive && (INT_MAX - curr < num * 10 || digits == 10)) return INT_MIN;
            num = num * 10 + (curr);   
            i++;
            digits++;
        }
        
        if (isPositive) return num;
        else return -1 * num;
    }
};