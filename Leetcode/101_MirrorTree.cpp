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
    bool checkSame(TreeNode* a, TreeNode* b) {
        
        // Base case
        if(a == NULL && b == NULL) {
            return true;
        }
        if(a == NULL || b == NULL) {
            return false;
        }
        
        if(a->val != b->val) {
            return false;
        }
        return checkSame(a->left, b->right) && checkSame(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        // Base case 
        if(root == NULL) {
            return true;
        }
        
        return checkSame(root->left, root->right);
    }
};