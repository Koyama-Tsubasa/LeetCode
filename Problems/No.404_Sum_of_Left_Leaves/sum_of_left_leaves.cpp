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
    int sumOfLeftLeaves(TreeNode* root) {
        
        // parameters
        std::queue<std::pair<TreeNode *, bool>> TNodes;
        int LL_sum = 0;

        // start computing
        TNodes.push({root, false});
        while (!TNodes.empty()) {

            auto [currNode, LoR] = TNodes.front();
            TNodes.pop();
            if ((currNode->left == nullptr) &&(currNode->right == nullptr))
                LL_sum += LoR ? currNode->val : 0;
            
            if (currNode->left) TNodes.push({currNode->left, true});
            if (currNode->right) TNodes.push({currNode->right, false});

        }

        return LL_sum;

    }
};
