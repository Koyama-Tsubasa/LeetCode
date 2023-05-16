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

    void PreOrder(TreeNode* r_node, int &sr_val, std::vector<TreeNode *> &psr_nodes) {

        if (r_node == nullptr) return;
        if (r_node->val == sr_val) psr_nodes.push_back(r_node);
        PreOrder(r_node->left, sr_val, psr_nodes);
        PreOrder(r_node->right, sr_val, psr_nodes);

    }

    bool is_same (TreeNode *node1, TreeNode *node2) {

        if ((node1 == nullptr) && (node2 == nullptr)) return true;
        else if ((node1 == nullptr) || (node2 == nullptr)) return false;
        else if (node1->val != node2->val) return false;
        else return (is_same(node1->left, node2->left) && is_same(node1->right, node2->right));

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // parameter
        std::vector<TreeNode *> potential_subroots;

        // start computing
        PreOrder(root, subRoot->val, potential_subroots);
        for (auto &node: potential_subroots)
            if (is_same(node, subRoot)) return true;
        
        return false;

    }
};
