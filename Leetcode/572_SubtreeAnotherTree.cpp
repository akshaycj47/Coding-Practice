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
    bool areIdentical(TreeNode* a, TreeNode* b) {
        
        // Base case
        if(a == NULL && b == NULL) {
            return true;
        }
        if(a == NULL || b == NULL) {
            return false;
        }
        
        return (a->val == b->val && areIdentical(a->left, b->left) && areIdentical(a->right, b->right));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        // Base case
        if(s == NULL) {
            return false;
        }
        if(t == NULL) {
            return true;
        }
        
        // Check if current nodes are identical subtrees
        if(areIdentical(s, t)) {
            return true;
        }
        
        // Check the left and right nodes now
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};