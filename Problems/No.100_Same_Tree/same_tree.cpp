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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // start compute, using inorder traversal method
        if (p!=NULL and q!=NULL) return isSameTree(p->left, q->left) and (p->val==q->val) and isSameTree(p->right, q->right);
        else if (p==NULL and q==NULL) return true;
        else return false;
        
    }
};
