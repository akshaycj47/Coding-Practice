#include <vector>
#include <queue>
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        
        // Final result
        std::vector<double> result;
        
        // Base case
        if(root == NULL) {
            return result;
        }
        
        // We will use queue for level order traversal
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        // Use a variable to store the sum of the levels, and another to store the number of
        // elements in a level
        double sum = 0;
        int n = 0;
        
        while(!q.empty()) {
            
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL) {
                double avg = double(sum) / n;
                result.push_back(avg);
                sum = 0;
                n = 0;
                if(!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                sum += curr->val;
                n++;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return result;
    }
};