class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // reference:
        // https://leetcode.com/problems/minimum-height-trees/solutions/1630778/c-simple-solution-topological-sort-w-explanation/

        // parameters
        std::vector<std::vector<int>> graph(n);
        std::vector<int> InDegrees(n, 0);
        std::vector<int> Roots_of_MHT;

        // start computing
        // remove easy cases
        if (n == 1) return {0};
        else if (n == 2) return {0, 1};
        else {

            // construct graph information & indegrees
            for (auto &edge: edges) {

                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);  
                InDegrees[edge[0]]++;
                InDegrees[edge[1]]++;

            }

            // find the leaf nodes
            std::queue<int> Leaves;
            for (int indgr=0; indgr<InDegrees.size(); indgr++) 
                if (InDegrees[indgr] == 1) Leaves.push(indgr);
            
            // using BFS to remove leaf nodes iteratively
            while (!Leaves.empty()) {

                Roots_of_MHT.clear();
                int leaf_size = Leaves.size();
                for (int i=0; i<leaf_size; i++) {

                    auto leaf = Leaves.front();
                    Leaves.pop();
                    Roots_of_MHT.push_back(leaf);

                    for (auto &adj_node: graph[leaf]) {

                        InDegrees[adj_node]--;
                        if (InDegrees[adj_node] == 1)
                            Leaves.push(adj_node);

                    }

                }

            }

            return Roots_of_MHT;

        }

    }
};
