#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = 0;
        int i = 0;
        int j = 0;
        int map[128] = {0};
        while (i < s.size() && j < s.size()) {
            if (map[s[j]] == 0) {
                map[s[j++]] = 1;
                len = std::max(len, j - i);
            }
            else {
                map[s[i++]] = 0;
            }
        }
        return len;
    }
};