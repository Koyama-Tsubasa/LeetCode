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
        std::queue<TreeNode*> Q, Q_clone;
        TreeNode *curr = NULL, *curr_clone = NULL;

        // start computing
        Q.push(original);
        Q_clone.push(cloned);
        while (!Q.empty()) {

            curr = Q.front();
            Q.pop();
            curr_clone = Q_clone.front();
            Q_clone.pop();
            if (curr == target) return curr_clone;

            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);

            if (curr_clone->left) Q_clone.push(curr_clone->left);
            if (curr_clone->right) Q_clone.push(curr_clone->right);

        }

        return NULL;

    }
};
