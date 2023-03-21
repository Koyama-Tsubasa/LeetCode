class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // parameters
        std::vector<std::vector<int>> edge_list(n);
        std::vector<bool> arrivable_nodes(n, false);
        std::queue<int> node2go;
        int curr;

        // start computing
        // collate edges
        for (auto &edge: edges) {

            edge_list[edge[0]].push_back(edge[1]);
            edge_list[edge[1]].push_back(edge[0]);

        }

        // start visiting
        node2go.push(source);
        arrivable_nodes[source] = true;
        while (!node2go.empty()) {

            curr = node2go.front();
            node2go.pop();
            
            if (curr == destination) return true;
            else {

                for (auto &node: edge_list[curr]) {
                    if (!arrivable_nodes[node]) {

                        arrivable_nodes[node] = true; 
                        node2go.push(node);

                    }
                }

            }

        }

        return false;

    }
};
