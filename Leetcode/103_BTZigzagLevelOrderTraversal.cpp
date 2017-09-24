#include <vector>
#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // Final result 
        std::vector<std::vector<int>> result;
        
        // Base case
        if(root == NULL) {
            return result;
        }
        
        // We will need two queues to perform zigzag traversal
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        q1.push(root);
        
        // Use a vector to store the elements of current level
        std::vector<int> level;
        
        while(!q1.empty() || !q2.empty()) {
            
            while(!q1.empty()) {
                TreeNode* curr = q1.front();
                q1.pop();
                level.push_back(curr->val);
                
                if(curr->left) q2.push(curr->left);
                if(curr->right) q2.push(curr->right);
            }
            
            if(q1.empty() && !level.empty()) {
                result.push_back(level);
                level.clear();
            }
            
            while(!q2.empty()) {
                TreeNode* curr = q2.front();
                q2.pop();
                level.insert(level.begin(), curr->val);
                
                if(curr->left) q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
            }
            
            if(q2.empty() && !level.empty()) {
                result.push_back(level);
                level.clear();
            }
        }
        
        return result;
    }
};