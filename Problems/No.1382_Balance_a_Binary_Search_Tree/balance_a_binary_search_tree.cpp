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

    // get inorder traversal of the BST
    void InOrderTraverse(TreeNode* node, std::vector<int> &inorder) {

        if (node == NULL) return;
        InOrderTraverse(node->left, inorder);
        inorder.push_back(node->val);
        InOrderTraverse(node->right, inorder);

    }

    // construct a new Balanced Binary Search Tree
    TreeNode *ConstructBBST(std::vector<int> &inorder, int left, int right) {

        if (left > right) return NULL;
        else {

            int mid = left + (right-left)/2;
            TreeNode *newNode = new TreeNode(inorder[mid]);
            newNode->left = ConstructBBST(inorder, left, mid-1);
            newNode->right = ConstructBBST(inorder, mid+1, right);

            return newNode;

        }

    }

    TreeNode* balanceBST(TreeNode* root) {

        // parameters
        std::vector<int> InOrder;
        TreeNode *BBST = NULL;

        // start computing
        InOrderTraverse(root, InOrder);
        BBST = ConstructBBST(InOrder, 0, InOrder.size()-1);

        return BBST;

    }
};
