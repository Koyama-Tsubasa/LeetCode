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
    vector<double> averageOfLevels(TreeNode* root) {
        
        // parameters
        std::vector<double> AverageValues;
        std::queue<TreeNode *> LevelValues;

        // start computing
        LevelValues.push(root);
        while (!LevelValues.empty()) {
            
            double levelAverage = 0;
            int LevelSize = LevelValues.size();
            for (int i=0; i<LevelSize; i++) {

                auto currNode = LevelValues.front();
                LevelValues.pop();
                levelAverage += (double)currNode->val;

                if (currNode->left) LevelValues.push(currNode->left);
                if (currNode->right) LevelValues.push(currNode->right);

            }
            AverageValues.push_back(levelAverage/LevelSize);

        }

        return AverageValues;

    }
};
