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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // parameter
        int next_tS;
        
        // start compute
        if (root == NULL) return false;
        else {
            
            // calculate the path sum of next targetSum, check the ending condition or continue finding
            next_tS = targetSum - root->val;
            if (next_tS==0 and root->left==NULL and root->right==NULL) return true;
            else return hasPathSum(root->left, next_tS) or hasPathSum(root->right, next_tS);
            
        }
        
    }
};
