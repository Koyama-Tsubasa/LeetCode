class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // parameters
        std::vector<std::vector<std::pair<int, int>>> flight_graph(n);
        std::queue<std::pair<int, int>> flight;
        std::vector<int> price_to_dest(n, INT_MAX);

        // start computing
        // construct graph information
        for (auto ticket: flights) {

            auto s = ticket[0], d = ticket[1], t_cost = ticket[2];
            flight_graph[s].push_back({d, t_cost});

        }

        // start visiting at most K stops using BFS & Dijkstra
        flight.push({src, 0});
        price_to_dest[src] = 0;
        for (int i=0; i<=k; i++) {

            int flight_count = flight.size();
            for (int j=0; j<flight_count; j++) {

                auto [dest, cost] = flight.front();
                flight.pop();
                
                for (auto [next_dst, added_price]: flight_graph[dest]) {
                    if ((cost + added_price) < price_to_dest[next_dst]) {

                        price_to_dest[next_dst] = cost + added_price;
                        flight.push({next_dst, price_to_dest[next_dst]});

                    }
                }

            }

        }

        return (price_to_dest[dst] != INT_MAX) ? price_to_dest[dst] : -1;

    }
};
