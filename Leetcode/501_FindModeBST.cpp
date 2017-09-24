#include <vector>
#include <map>

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
    void traverse(TreeNode* root, std::map<int, int>& m) {
        
        // Base case
        if(root == NULL) return;
        
        // Fill out the map
        if(m.find(root->val) == m.end()) {
            m[root->val] = 1;
        }
        else {
            m[root->val] += 1;
        }
        
        // Perform traversal on child nodes
        traverse(root->left, m);
        traverse(root->right, m);
    }
    
    std::vector<int> findMode(TreeNode* root) {
        
        std::map<int, int> m;
        traverse(root, m);
        
        std::map<int, int>::iterator it;
        
        // Find out maximum frequency
        int max = 0;
        for(it = m.begin(); it != m.end(); it++) {
            if(it->second > max) {
                max = it->second;
            }
        }
        
        std::vector<int> mode;
        for(it = m.begin(); it!= m.end(); it++) {
            if(it->second == max) {
                mode.push_back(it->first);
            }
        }
        
        return mode;
    }
};