#include <vector>
#include <algorithm>

class Solution {
public:
    void combinationSumUtil(std::vector<int>& candidates, int target, int i, std::vector<int> ans, std::vector<std::vector<int>>& result) {
        
        // Combination cannot be found
        if(target < 0) return;
        
        // Combination is found
        if(target == 0) {
            result.push_back(ans);
            return;
        }
        
        for(int k = i; k < candidates.size() && target - candidates[k] >= 0; k++) {
            ans.push_back(candidates[k]);
            combinationSumUtil(candidates, target - candidates[k], k, ans, result);
            ans.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        
        // Final result
        std::vector<std::vector<int>> result;
        
        // Base case
        if(candidates.size() == 0) return result;
        
        // Current list
        std::vector<int> ans;
        
        // Sort the candidates
        std::sort(candidates.begin(), candidates.end());
        
        combinationSumUtil(candidates, target, 0, ans, result);
        
        // Combinations found
        return result;
    }
};