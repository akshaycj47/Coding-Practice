#include <vector>

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
    void inorderTraversalUtil(TreeNode* root, std::vector<int>& result) {
        
        if(root == NULL) return;
        
        inorderTraversalUtil(root->left, result);
        result.push_back(root->val);
        inorderTraversalUtil(root->right, result);
    }
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        
        std::vector<int> result;
        inorderTraversalUtil(root, result);
        
        return result;
    }
};