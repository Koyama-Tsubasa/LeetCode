class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # parameters
        rowS = len(grid)
        colS = len(grid[0])

        # start computing

        # calculate the first row & the first column
        for i in range(1, colS):
            grid[0][i] += grid[0][i-1]
        for i in range(1, rowS):
            grid[i][0] += grid[i-1][0]

        # calculate the other nums
        for i in range(1, rowS):
            for j in range(1, colS):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])

        return grid[-1][-1]
