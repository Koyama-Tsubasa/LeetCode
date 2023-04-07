class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        // parameter
        int MAX_star_sum = INT_MIN;
        int node_size = vals.size();
        std::vector<std::vector<int>> edge_weight(node_size);

        // start computing
        // construct graph information
        for (auto &edge: edges) {

            edge_weight[edge[0]].push_back(vals[edge[1]]);
            edge_weight[edge[1]].push_back(vals[edge[0]]);

        }

        // start compare all possible star graph
        for (int i=0; i<node_size; i++) {

            int star_sum = vals[i];
            auto edge_information = edge_weight[i];
            int edge_size = edge_information.size();

            std::sort(edge_information.rbegin(), edge_information.rend());
            for (int e=0; e<std::min(edge_size, k); e++) {

                if (edge_information[e] > 0) star_sum += edge_information[e];
                else break;

            }

            MAX_star_sum = std::max(MAX_star_sum, star_sum);

        }

        return MAX_star_sum;

    }
};
