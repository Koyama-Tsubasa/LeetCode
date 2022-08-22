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
    vector<int> preorderTraversal(TreeNode* root) {
        
        // parameters
        vector<int> ans;
        TreeNode *temp = root, *prev;
        
        // start compute, using Morris Traversal
        while (temp) {
            
            if (temp->left == NULL) {
                
                ans.push_back(temp->val);
                temp = temp->right;
                
            }
            else {
                
                prev = temp->left;
                while (prev->right and prev->right!=temp) prev = prev->right;
                if (prev->right == NULL) {
                    
                    ans.push_back(temp->val);
                    prev->right = temp;
                    temp = temp->left;
                    
                }
                else {
                    
                    prev->right = NULL;
                    temp = temp->right;
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};
