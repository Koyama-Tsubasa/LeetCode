class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // parameters
        std::vector<int> starting_nodes;
        std::vector<bool> node_no_InDegree(n, true);

        // start computing
        for (auto &edge: edges) node_no_InDegree[edge[1]] = false;
        for (int i=0; i<n; i++) 
            if (node_no_InDegree[i] == true) starting_nodes.push_back(i);

        return starting_nodes;

    }
};
