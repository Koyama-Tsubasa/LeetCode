class Solution(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """

        # Depth-First Search
        def DFS(row, col):
            if ((row >= m) or (col >= n) or (grid[row][col] == 0)):
                return False
            elif ((row == m-1) and (col == n-1)):
                return True
            else:
                grid[row][col] = 0
                return (DFS(row+1, col) or DFS(row, col+1))
        

        # parameters
        paths = 0
        m, n = len(grid), len(grid[0])

        # start computing
        if (grid[0][0] == 0):
            return True
        paths = DFS(0, 0)
        grid[0][0] = 1
        paths += DFS(0, 0)

        return (paths < 2)
