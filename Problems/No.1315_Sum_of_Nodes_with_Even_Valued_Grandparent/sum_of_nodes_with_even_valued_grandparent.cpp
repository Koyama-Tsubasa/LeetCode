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
    int sumEvenGrandparent(TreeNode* root) {
        
        // parameters
        int EG_sum = 0;
        TreeNode *CNode = nullptr;
        std::queue<TreeNode *> Nodes;

        // start computing
        if (root == nullptr) return 0;
        else {
            
            Nodes.push(root);
            while (!Nodes.empty()) {

                CNode = Nodes.front();
                Nodes.pop();
                if (CNode->val%2 == 0) {

                    if (CNode->left) {

                        if (CNode->left->left) EG_sum += CNode->left->left->val;
                        if (CNode->left->right) EG_sum += CNode->left->right->val;

                    }

                    if (CNode->right) {

                        if (CNode->right->left) EG_sum += CNode->right->left->val;
                        if (CNode->right->right) EG_sum += CNode->right->right->val;

                    }

                }

                if (CNode->left) Nodes.push(CNode->left);
                if (CNode->right) Nodes.push(CNode->right);

            }

            return EG_sum;

        }

    }
};
