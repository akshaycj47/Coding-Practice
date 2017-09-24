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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        
        // Store the final result
        std::vector<std::vector<int>> result;
        
        // Base case
        if(root == NULL) {
            return result;
        }
        
        // Queue helps in level order traversal
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        // Vector to store the elements of current level
        std::vector<int> level;
        
        while(!q.empty()) {
            
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL) {
                result.push_back(level);
                level.clear();
                if(!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        // Return final result
        return result;
    }
};