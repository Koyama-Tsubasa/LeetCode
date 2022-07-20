/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        // parameters
        int left, right;
        
        // start compute
        if (root == NULL) return 0;
        else {
            
            left = minDepth(root->left);
            right = minDepth(root->right);
            return (!min(left, right)) ? max(left, right)+1 : min(left, right)+1;
            
        }
        
    }
};
