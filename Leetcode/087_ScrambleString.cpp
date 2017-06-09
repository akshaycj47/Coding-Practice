#include <string>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        
        // If both strings are empty, return true
        if(s1.size() == 0 && s2.size() == 0) {
            return true;
        }
        
        // If strings are not of the same size, then s2 cannot be a scrambled string of s1
        if(s1.size() != s2.size()) {
            return false;
        }
        
        // If both the strings have size 1, then both have to be the same
        if(s1.size() == 1 && s2.size() == 1) {
            return s1 == s2;
        }
        
        // Check if all alphabets in two strings are same or not
        // Assuming strings are lower case
        int m[26] = {0};
        for(int i = 0; i < s1.size(); i++) {
            m[s1[i] - 'a']++;
            m[s2[i] - 'a']--;
        }
        
        // Check if any mismatch
        for(int i = 0; i < 26; i++) {
            if(m[i] != 0) {
                return false;
            }
        }
        
        // Try scrambling for different sizes
        for(int i = 1; i < s1.size(); i++) {
            
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)))) {
                return true;
            }
            if((isScramble(s1.substr(0, i), s2.substr(s1.size() - i, i)) && 
                isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)))) {
                return true;
            }
        }
        
        return false;
    }
};
