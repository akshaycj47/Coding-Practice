#include <climits>

class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0) {
            return 0;
        }
        
        int lo = 0;
        int hi = INT_MAX;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(mid > x / mid) {
                hi = mid - 1;
            }
            else if(mid + 1 > x / (mid + 1)) {
                return mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};