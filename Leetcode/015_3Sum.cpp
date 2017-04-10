#include <vector>
#include <utility>
#include <unordered_map>
#include <map>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // Solution
        std::vector<std::vector<int>> v;
        
        // Add elements to the map based on their count;
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            }
            else {
                m[nums[i]] = m[nums[i]] + 1;
            }
        }
        
        // Base case for all 0s
        if (m.size() == 1 && m.find(0) != m.end() && m[0] >= 3) {
            std::vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            v.push_back(temp);
            return v;
        }
        
        // Start looking for pairs whose sum will be equal to the negative of 
        // key of map
        std::map<std::pair<int, int>, bool> d;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int search = -1 * (nums[i] + nums[j]);
                if (m.find(search) != m.end()) {
                    // Found it
                    m[search] = m[search] - 1;
                    m[nums[i]] = m[nums[i]] - 1;
                    m[nums[j]] = m[nums[j]] - 1;
                    
                    if (m[search] >= 0 && m[nums[i]] >= 0 && m[nums[j]] >= 0) {
                        std::vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(search);
                        std::sort(temp.begin(), temp.end());
                        if (d.find(std::make_pair(temp[0], temp[1])) == d.end()) {
                            v.push_back(temp);
                            d[std::make_pair(temp[0], temp[1])] = true;
                        }
                    }
                    m[search] = m[search] + 1;
                    m[nums[i]] = m[nums[i]] + 1;
                    m[nums[j]] = m[nums[j]] + 1;
                }
            }
        }
        
        return v;
    }
};