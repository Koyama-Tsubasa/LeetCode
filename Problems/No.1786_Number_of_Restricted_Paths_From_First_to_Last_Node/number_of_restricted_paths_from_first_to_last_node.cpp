class Solution {
public:

    // find restricted paths from source (s) to destination (d)
    int FindRestrictedPaths(int s, int d, std::vector<std::vector<std::pair<int, int>>> &G, std::vector<int> &D, std::vector<int> &Rpaths) {

        if (s == d) return 1;
        else if (Rpaths[s] != -1) return Rpaths[s];
        else {

            int Rpath = 0;
            for (auto &[adj_node, EWeight]: G[s]) 
                if (D[adj_node] < D[s])
                    Rpath = (Rpath + FindRestrictedPaths(adj_node, d, G, D, Rpaths)) % 1000000007;
            
            Rpaths[s] = Rpath;
            return Rpath;

        }

    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        // reference:
        // https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/solutions/3332377/c-well-commented-avoid-getting-wa-in-the-last-testcase/

        // parameters
        int restricted_paths_to_n = 0;
        std::vector<std::vector<std::pair<int, int>>> graph(n+1);
        std::vector<int> dist(n+1, INT_MAX);
        std::vector<int> restricted_paths(n+1, -1);

        // create graph information
        for (auto &edge: edges) {

            int node1 = edge[0];
            int node2 = edge[1];
            int weight = edge[2];

            graph[node1].push_back({node2, weight});
            graph[node2].push_back({node1, weight});

        }

        // find the shortest path from node n using Dijsktra's Algorithm
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>,
            std::greater<>> min_path;
        min_path.push({0, n});
        dist[n] = 0;
        while (!min_path.empty()) {

            auto [curr_weight, curr_node] = min_path.top();
            min_path.pop();

            for (auto &[adj_node, edge_weight]: graph[curr_node]) 
                if (dist[adj_node] > dist[curr_node] + edge_weight) {
                    
                    dist[adj_node] = dist[curr_node] + edge_weight;
                    min_path.push({dist[adj_node], adj_node});

                }

        }

        // find all possible restricted paths to n
        restricted_paths_to_n = FindRestrictedPaths(1, n, graph, dist, restricted_paths);

        return restricted_paths_to_n;

    }
};
