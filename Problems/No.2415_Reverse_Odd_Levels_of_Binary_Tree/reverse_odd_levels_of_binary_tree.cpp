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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        // parameters
        bool Odd = false;
        std::queue<TreeNode *> TNodes;
        std::vector<int> LevelValues;

        // start computing
        TNodes.push(root);
        while(!TNodes.empty()) {

            if (!Odd) {

                LevelValues.clear();
                LevelValues.shrink_to_fit();

            }

            int LevelNodes = TNodes.size();
            for (int i=0; i<LevelNodes; i++) {

                auto currNode = TNodes.front();
                TNodes.pop();

                if (Odd) currNode->val = LevelValues[LevelNodes-1-i];

                if (currNode->left) {

                    TNodes.push(currNode->left);
                    LevelValues.push_back(currNode->left->val);

                }
                if (currNode->right) {

                    TNodes.push(currNode->right);
                    LevelValues.push_back(currNode->right->val);

                }

            }

            Odd ^= true;

        }

        return root;

    }
};
