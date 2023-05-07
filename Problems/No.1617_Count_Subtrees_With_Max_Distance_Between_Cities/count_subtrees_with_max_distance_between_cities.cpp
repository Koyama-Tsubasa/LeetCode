class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        // parameters
        std::vector<int> dis_cnt(n-1, 0);
        std::unordered_map<int, std::vector<int>> edge_info;

        // start computing
        // construct edge information
        for (auto &edge: edges) {

            int city_1 = edge[0], city_2 = edge[1];
            edge_info[city_1].push_back(city_2);
            edge_info[city_2].push_back(city_1);

        }
        
        // check all possible enumerations
        dis_cnt[0] = edges.size();
        for (int i=0; i<std::pow(2, n); i++) {

            // decide current subset and check if it's size > 1
            std::unordered_set<int> curr_subset;
            for (int j=0; j<n; j++)
                if ((i & (1<<j)) != 0) curr_subset.insert(j+1);
            if (curr_subset.size() < 3) continue;

            // calculate the max distance of this subset
            int MAX_distance = 0;
            for (auto &city: curr_subset) {
                
                int curr_distance = -1;
                auto subset_copy = curr_subset;

                // visit from each city in the current subset using queue
                std::queue<int> visit_city;
                visit_city.push(city);
                subset_copy.erase(city);
                while (!visit_city.empty()) {

                    curr_distance++;
                    int Q_size = visit_city.size();
                    for (int cnt=0; cnt<Q_size; cnt++) {

                        int curr_city = visit_city.front();
                        visit_city.pop();
                        for (auto &next_city: edge_info[curr_city]) 
                            if (subset_copy.count(next_city)) {

                                visit_city.push(next_city);
                                subset_copy.erase(next_city);

                            }

                    }

                }

                // check if every cities in the subset can be visited
                if (!subset_copy.empty()) break;
                else MAX_distance = std::max(MAX_distance, curr_distance);
                
            }
            if (MAX_distance > 1) dis_cnt[MAX_distance-1]++;

        }

        return dis_cnt;

    }
};
