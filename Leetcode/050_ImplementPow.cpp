#include <climits>

class Solution {
public:
    double myPow(double x, int n) {
        
        // Base case
        if(n < 0) {
            if(x == -1 && n == INT_MIN) {
                return 1;
            }
            if(n == INT_MIN) {
                return 1 / myPow(x, INT_MAX);
            }
            return 1 / myPow(x, n * -1);
        }
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return x;
        }
        
        // Divide and conquer
        double temp = myPow(x, n / 2);
        if(n % 2 == 0) {
            return temp * temp;
        }
        
        else {
            return x * temp * temp;
        }
    }
};