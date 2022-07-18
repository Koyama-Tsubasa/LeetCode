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
    
    // calculate the height and if it is balanced
    int balanced_height(TreeNode* node, bool *balanced) {
        
        if (node == NULL) return 0;
        else {
            
            int left = balanced_height(node->left, balanced);
            int right = balanced_height(node->right, balanced);
            
            if (abs(left-right)>1) *balanced = false;
            return max(left, right) + 1;
            
        }
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        // parameter
        bool balanced = true;
        
        // start compute
        if (root == NULL) return true;
        else if (abs(balanced_height(root->left, &balanced)-balanced_height(root->right, &balanced))<=1) return balanced;
        else return false;
        
    }
};
