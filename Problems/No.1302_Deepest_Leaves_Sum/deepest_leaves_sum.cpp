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
    int deepestLeavesSum(TreeNode* root) {
        
        // parameters
        std::queue<TreeNode *> nodes;
        TreeNode *curr = NULL;
        int DL_sum, Q_size;

        // start computing
        nodes.push(root);
        while (!nodes.empty()) {

            DL_sum = 0;
            Q_size = nodes.size();

            for (int i=0; i<Q_size; i++) {

                curr = nodes.front();
                nodes.pop();
                DL_sum += curr->val;

                if (curr->left) nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);

            }

        }

        return DL_sum;

    }
};
