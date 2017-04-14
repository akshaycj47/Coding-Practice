#include <vector>
#include <algorithm>

class Solution {
public:
    void combinationSum2Util(std::vector<int>& candidates, int target, int i, std::vector<int> ans, std::vector<std::vector<int>>& result) {
        
        // If combination not possible
        if(target < 0) {
            return;
        }
        
        // If combination is found
        if(target == 0) {
            result.push_back(ans);
            return;
        }
        
        // Try combinations
        for(int k = i; k < candidates.size() && target < candidates[k] >= 0; k++) {
            if(k == i || candidates[k] != candidates[k - 1]) {
                ans.push_back(candidates[k]);
                combinationSum2Util(candidates, target - candidates[k], k + 1, ans, result);
                ans.pop_back();
            }
            
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        
        // Final result
        std::vector<std::vector<int>> result;
        
        // Base case
        if(candidates.size() == 0 || target < 0) {
            return result;
        }
        
        // Current combination
        std::vector<int> ans;
        
        // Sort the combinations
        std::sort(candidates.begin(), candidates.end());
        
        combinationSum2Util(candidates, target, 0, ans, result);
        
        return result;
    }
};