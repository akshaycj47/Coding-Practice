#include <algorithm>
#include <cmath>

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
    int findDepth(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        int lDepth = findDepth(root->left);
        int rDepth = findDepth(root->right);
        return 1 + std::max(lDepth, rDepth);
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) {
            return true;
        }
        
        int lDepth = findDepth(root->left);
        int rDepth = findDepth(root->right);
        int diff = std::abs(lDepth - rDepth);
        
        return (diff <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};