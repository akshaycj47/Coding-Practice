#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        
        // Final result
        std::vector<std::vector<std::string>> result;
        
        // Create a map
        std::map<std::string, std::vector<std::string>> m;
        
        // Insert strings into maps, and group them in terms of anagrams
        // To find anagrams, we will rearrange characters of string in ascending order
        for(int i = 0; i < strs.size(); i++) {
            
            std::string key = strs[i];
            std::sort(key.begin(), key.end());
            
            // If key is already generated
            if(m.find(key) != m.end()) {
                m[key].push_back(strs[i]);
            }
            
            // If new key
            else {
                std::vector<std::string> temp;
                m[key] = temp;
                m[key].push_back(strs[i]);
            }
        }
        
        // Iterate through the map and add groups to the result
        std::map<std::string, std::vector<std::string>>::iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};