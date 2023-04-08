class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # reference:
        # https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/524936/c-0-1-bfs-o-n-instead-of-o-nlogn/

        # parameters
        final_cost = 0
        m, n = len(grid), len(grid[0])
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        visited = [False] * (m*n)
        next_grid_with_less_cost = []

        # start computing
        next_grid_with_less_cost.append([0, 0])
        while next_grid_with_less_cost:
            [curr_grid, curr_cost] = next_grid_with_less_cost.pop(0)

            # check if the current grid is visited, if not then it is the shortest path
            curr_grid_r = curr_grid // n
            curr_grid_c = curr_grid % n
            if not visited[curr_grid]:
                visited[curr_grid] = True
                final_cost = curr_cost

            # check if the current grid is the goal
            if (curr_grid == m*n-1):
                break
            else:
                # check the surrounding grids
                for [vr, vc] in dirs:
                    next_r = curr_grid_r + vr
                    next_c = curr_grid_c + vc
                    next_grid = next_r*n + next_c
                    if ((next_r < 0) or (next_r >= m) or (next_c < 0) or (next_c >= n) or visited[next_grid]):
                        continue
                    
                    # check if it has to change the pointer
                    add_cost = False
                    if not (((grid[curr_grid_r][curr_grid_c] == 1) and (vr == 0) and (vc == 1)) or
                            ((grid[curr_grid_r][curr_grid_c] == 2) and (vr == 0) and (vc == -1)) or
                            ((grid[curr_grid_r][curr_grid_c] == 3) and (vr == 1) and (vc == 0)) or
                            ((grid[curr_grid_r][curr_grid_c] == 4) and (vr == -1) and (vc == 0))):
                        add_cost = True
                    
                    # add the result into the dequeue, higher priority for the unchanged pointer
                    if not add_cost:
                        next_grid_with_less_cost.insert(0, [next_grid, curr_cost])
                    else:
                        next_grid_with_less_cost.append([next_grid, curr_cost + 1])
        
        return final_cost
