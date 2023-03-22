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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // parameters
        std::queue<std::pair<TreeNode*, TreeNode*>> TNodes;
        std::pair<TreeNode*, TreeNode*> curr_pair;

        // start computing
        if (root1 == nullptr) return root2;
        else if (root2 == nullptr) return root1;
        else {

            TNodes.push(std::make_pair(root1, root2));
            while (!TNodes.empty()) {

                curr_pair = TNodes.front();
                TNodes.pop();

                if ((curr_pair.first == nullptr) || (curr_pair.second == nullptr)) continue;
                else {

                    curr_pair.first->val += curr_pair.second->val;

                    if (curr_pair.first->left) TNodes.push(std::make_pair(curr_pair.first->left, curr_pair.second->left));
                    else curr_pair.first->left = curr_pair.second->left;
                    if (curr_pair.first->right) TNodes.push(std::make_pair(curr_pair.first->right, curr_pair.second->right));
                    else curr_pair.first->right = curr_pair.second->right;

                }

            }

            return root1;

        }

    }
};
