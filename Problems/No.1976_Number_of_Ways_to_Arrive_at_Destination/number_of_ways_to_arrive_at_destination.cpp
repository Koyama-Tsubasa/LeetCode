class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // global parameters
        static const int mod = 1e9 + 7;
        std::vector<std::pair<long long, long long>> edges[n];

        // start computing
        // construct graph (edge relationships)
        for (auto &road: roads) {

            edges[road[0]].push_back({road[1], road[2]});
            edges[road[1]].push_back({road[0], road[2]});

        }

        // traverse using Dijkstra's Algorithm
        // local parameters
        int traverse_count = 0;
        std::priority_queue<
            std::pair<long long, long long>, 
            std::vector<std::pair<long long, long long>>, 
            std::greater<>> min_path;
        std::vector<long long> dist(n, LLONG_MAX), paths(n, 0);

        // start traverse
        dist[0] = 0;
        paths[0] = 1;
        min_path.push({0, 0});
        while (traverse_count < n) {

            auto [curr_dist, curr_node] = min_path.top();
            min_path.pop();

            if (dist[curr_node] < curr_dist) continue;
            else {

                // update the distance to the adjacent node from current node
                for (auto &[adj_node, edgeW]: edges[curr_node]) {

                    auto updated_dist = curr_dist + edgeW;
                    if (updated_dist < dist[adj_node]) {

                        dist[adj_node] = updated_dist;
                        min_path.push({updated_dist, adj_node});
                        paths[adj_node] = paths[curr_node];

                    }
                    else if (updated_dist == dist[adj_node]) 
                        paths[adj_node] = (paths[adj_node] + paths[curr_node]) % mod;

                }
                traverse_count++;

            }

        }

        return (paths[n-1] % mod);

    }
};
