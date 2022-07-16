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
    
    bool checkSymmetric(TreeNode* p, TreeNode* q)  {
        
        if (p!=NULL and q!=NULL) return checkSymmetric(p->left, q->right) and (p->val==q->val) and checkSymmetric(p->right, q->left);
        else if (p==NULL and q==NULL) return true;
        else return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return checkSymmetric(root->left, root->right);
        
    }
};
