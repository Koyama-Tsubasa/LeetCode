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

    // search all Binary Tree paths
    void searchBTpaths(TreeNode* tNode, std::string temp, std::vector<std::string> &PVector) {

        if (tNode == NULL) return;
        else {

            temp += std::to_string(tNode->val);
            if ((tNode->left == NULL) && (tNode->right == NULL)) PVector.push_back(temp);
            else {

                temp += "->";
                searchBTpaths(tNode->left, temp, PVector);
                searchBTpaths(tNode->right, temp, PVector);

            }

        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        // parameter
        std::vector<std::string> BTPaths;

        // start computing
        searchBTpaths(root, "", BTPaths);

        return BTPaths;

    }
};
