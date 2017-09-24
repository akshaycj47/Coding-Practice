#include <algorithm>
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
    int minDepth(TreeNode* root) {
        
        // Base case
        if(root == NULL) {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        // Calculate minimum depths for left and right subtree
        int leftMin = root->left != NULL ? minDepth(root->left) : INT_MAX;
        int rightMin = root->right != NULL ? minDepth(root->right) : INT_MAX;
        
        return 1 + std::min(leftMin, rightMin);
    }
};