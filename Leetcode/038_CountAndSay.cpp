#include <string>

class Solution {
public:
    std::string countAndSayUtil(std::string curr) {
        
        std::string ans = "";
        int i = 0;
        int count = 0;
        char temp = curr[0];
        while(i < curr.size()) {
            
            // If same
            if(curr[i] == temp) {
                count++;
                i++;
            }
            
            // If different or reached the end of string
            if(i > curr.size() || curr[i] != temp) {
                ans = ans + std::to_string(count) + temp;
                count = 0;
                temp = curr[i];
            }
        }
        return ans;
    }

    std::string countAndSay(int n) {
        
        // Base case
        if(n < 1) return "";
        
        std::string ans = "";
        for(int i = 1; i <= n; i++) {
            
            if(i == 1) {
                ans = "1";
            }
            else {
                ans = countAndSayUtil(ans);
            }
        }
        
        return ans;
    }
};