class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // parameter
        std::vector<std::vector<int>> c2c_dist(n, std::vector<int>(n, INT_MAX));

        // start computing
        // Floyd Warshall for all paths
        for (auto edge: edges) {

            c2c_dist[edge[0]][edge[1]] = edge[2];
            c2c_dist[edge[1]][edge[0]] = edge[2];

        }
        for (int i=0; i<n; i++) c2c_dist[i][i] = 0;

        for (int mid=0; mid<n; mid++)
            for (int start=0; start<n; start++)
                for (int end=0; end<n; end++) {

                    if ((c2c_dist[start][mid] == INT_MAX) || (c2c_dist[mid][end] == INT_MAX)) continue;
                    else c2c_dist[start][end] = std::min(c2c_dist[start][end], c2c_dist[start][mid] + c2c_dist[mid][end]);

                }

        // find the greatest number of smallest reachable cities
        int Gcity = -1;
        int Mcity_num = n;

        for (int city=0; city<n; city++) {

            int cnt = 0;
            for (int adj_city=0; adj_city<n; adj_city++)
                if (c2c_dist[city][adj_city] <= distanceThreshold) cnt++;
            
            if (cnt <= Mcity_num) {

                Mcity_num = cnt;
                Gcity = city;

            }

        }

        return Gcity;

    }
};
