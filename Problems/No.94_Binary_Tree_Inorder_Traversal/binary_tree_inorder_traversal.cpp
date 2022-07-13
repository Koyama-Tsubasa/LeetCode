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
    
    // Binary Tree Inorder Traversal
    void BTIT(TreeNode* node, vector<int> &ans) {
        
        if (node != NULL) {
            
            BTIT(node->left, ans);
            ans.push_back(node->val);
            BTIT(node->right, ans);
            
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        // parameters
        vector<int> BTIT_ans;
        
        // start compute
        if (root != NULL) {
            
            BTIT(root->left, BTIT_ans);
            BTIT_ans.push_back(root->val);
            BTIT(root->right, BTIT_ans);
            
        }
        
        return BTIT_ans;
        
    }
};
