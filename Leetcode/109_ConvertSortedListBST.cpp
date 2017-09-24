#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBSTUtil(std::vector<int>& v, int lo, int hi) {
        
        // Base case
        if(lo > hi) {
            return NULL;
        }
        
        // Create a node from the middle element in the array
        int mid = lo + (hi - lo) / 2;
        TreeNode* curr = new TreeNode(v[mid]);
        
        // Find the child nodes
        curr->left = sortedListToBSTUtil(v, lo, mid - 1);
        curr->right = sortedListToBSTUtil(v, mid + 1, hi);
        
        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        // Create a vector and fill up the vector with the sorted list elements
        std::vector<int> v;
        ListNode* temp = head;
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        return sortedListToBSTUtil(v, 0, v.size() - 1);
    }
};