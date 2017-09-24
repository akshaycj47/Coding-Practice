#include <climits>

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
    bool isValidBSTUtil(TreeNode* root, long min, long max) {
        
        // Base case
        if(root == NULL) return true;
        
        return (root->val > min && root->val < max) && isValidBSTUtil(root->left, (long)min, root->val) && isValidBSTUtil(root->right, root->val, (long)max);
    }
    
    bool isValidBST(TreeNode* root) {
        
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
    }
};