#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(target - nums[i]) != m.end()) {
                result.push_back(m[target - nums[i]]);
                result.push_back(i + 1);
                return result;
            }
            m[nums[i]] = i + 1;
        }
        return result;
    }
};