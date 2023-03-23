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
    bool isCousins(TreeNode* root, int x, int y) {
        
        // parameters
        int xParent, yParent, xDepth, yDepth;
        std::queue<std::pair<TreeNode *, int>> TNodes;

        // start computing
        TNodes.push({root, 0});
        while (!TNodes.empty()) {

            auto [currNode, currDepth] = TNodes.front();
            TNodes.pop();
            currDepth++;

            if (currNode->left) {

                TNodes.push({currNode->left, currDepth});

                if (currNode->left->val == x) {

                    xParent = currNode->val;
                    xDepth = currDepth;

                }
                else if (currNode->left->val == y) {

                    yParent = currNode->val;
                    yDepth = currDepth;

                }

            }
            if (currNode->right) {

                TNodes.push({currNode->right, currDepth});

                if (currNode->right->val == x) {

                    xParent = currNode->val;
                    xDepth = currDepth;

                }
                else if (currNode->right->val == y) {

                    yParent = currNode->val;
                    yDepth = currDepth;

                }

            }

        }

        return ((xDepth == yDepth) && (xParent != yParent));

    }
};
