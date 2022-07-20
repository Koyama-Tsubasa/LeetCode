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
        queue<TreeNode*> Q;
        TreeNode *temp;
        int depth = 0, Q_size;
        
        // start compute, using BFS method
        if (root == NULL) return 0;
        else {
            
            Q.emplace(root);
            while (Q.size()) {
                
                Q_size = Q.size();
                for (int i=0; i<Q_size; i++) {
                    
                    temp = Q.front();
                    Q.pop();
                    
                    if (temp->left==NULL and temp->right==NULL) return depth + 1;
                    else{
                        
                        if (temp->left) Q.emplace(temp->left);
                        if (temp->right) Q.emplace(temp->right);
                        
                    }
                    
                }    
                
                depth++;
                
            }
            
            return depth;
            
        }
        
    }
};
