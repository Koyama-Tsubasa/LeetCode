/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        // parameters
        std::queue<Node *> TNodes;
        int MaxDepth = 0;

        // start computing
        if (root == nullptr) return 0;
        TNodes.push(root);
        while (!TNodes.empty()) {

            int LevelSize = TNodes.size();
            for (int i=0; i<LevelSize; i++) {

                auto currNode = TNodes.front();
                TNodes.pop();
                for (auto child: currNode->children) TNodes.push(child);

            }
            
            MaxDepth++;

        }

        return MaxDepth;

    }
};
