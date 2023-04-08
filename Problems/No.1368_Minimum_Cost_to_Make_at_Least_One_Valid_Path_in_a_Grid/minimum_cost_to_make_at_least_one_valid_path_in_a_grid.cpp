class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        // reference:
        // https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/524936/c-0-1-bfs-o-n-instead-of-o-nlogn/

        // parameters
        int final_cost = 0;
        int m = grid.size(), n = grid[0].size();
        std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<bool> visited(m*n, false);
        std::deque<std::pair<int, int>> next_grid_with_less_cost;

        // start computing
        next_grid_with_less_cost.push_back({0, 0});
        while (!next_grid_with_less_cost.empty()) {

            auto [curr_grid, curr_cost] = next_grid_with_less_cost.front();
            next_grid_with_less_cost.pop_front();

            // check if the current grid is visited, if not then it is the shortest path
            int curr_grid_r = curr_grid / n;
            int curr_grid_c = curr_grid % n;
            if (visited[curr_grid] == false) {

                visited[curr_grid] = true;
                final_cost = curr_cost;

            }
            
            // check if the current grid is the goal
            if ((curr_grid_r == m-1) && (curr_grid_c == n-1)) break;
            else {
                
                // check the surrounding grids
                for (auto &[vr, vc]: dirs) {

                    int next_r = curr_grid_r + vr;
                    int next_c = curr_grid_c + vc;
                    int next_grid = next_r*n + next_c;
                    if ((next_r < 0) || (next_r >= m) || (next_c < 0) || (next_c >= n) || 
                        (visited[next_grid] == true)) continue;
                    
                    // check if it has to change the pointer
                    bool add_cost = false;
                    if (!(((grid[curr_grid_r][curr_grid_c] == 1) && (vr == 0) && (vc == 1)) ||
                          ((grid[curr_grid_r][curr_grid_c] == 2) && (vr == 0) && (vc == -1)) ||
                          ((grid[curr_grid_r][curr_grid_c] == 3) && (vr == 1) && (vc == 0)) ||
                          ((grid[curr_grid_r][curr_grid_c] == 4) && (vr == -1) && (vc == 0))))
                        add_cost = true;
                    
                    // add the result into the dequeue, higher priority for the unchanged pointer
                    if (add_cost == false) next_grid_with_less_cost.push_front({next_grid, curr_cost});
                    else next_grid_with_less_cost.push_back({next_grid, curr_cost + 1});

                }

            }

        }

        return final_cost;

    }
};
