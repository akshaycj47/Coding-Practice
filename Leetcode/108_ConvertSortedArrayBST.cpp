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
    // Utility function that will help us convert sorted array to BST
    TreeNode* sortedArrayToBSTUtil(std::vector<int>& nums, int lo, int hi) {
        
        // Base case
        if(lo > hi) {
            return NULL;
        }
        
        // Find the middle element
        int mid = lo + (hi - lo) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        
        // Find the child elements for curr
        curr->left = sortedArrayToBSTUtil(nums, lo, mid - 1);
        curr->right = sortedArrayToBSTUtil(nums, mid + 1, hi);
        
        return curr;
    }
    
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        
        return sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
    }
};