#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        
        // Base condition
        if(needle.size() == 0) {
            return 0;
        }
        if(haystack.size() < needle.size()) {
            return -1;
        }
        
        // Check for substring
        int index = -1;
        char start = needle[0];
        for(int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            
            if(haystack[i] == start && haystack.compare(i, needle.size(), needle) == 0) {
                return i;
            }
        }
        return index;
    }
};