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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        // parameters
        std::queue<TreeNode*> Q;
        TreeNode *curr = NULL;

        // start computing
        Q.push(cloned);
        while (!Q.empty()) {

            curr = Q.front();
            Q.pop();
            if (curr->val == target->val) return curr;

            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);

        }

        return NULL;

    }
};
