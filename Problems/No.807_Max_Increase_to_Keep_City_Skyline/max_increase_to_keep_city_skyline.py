class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # parameters
        increased = 0
        max_col, max_row = [0]*len(grid[0]), [0]*len(grid)

        # start computing
        # find the maximum of each column
        for col in range(len(grid[0])):
            for row in range(len(grid)):
                max_col[col] = max(max_col[col], grid[row][col])
        
        # find the maximum of each row & start increasing
        for row in range(len(grid)):
            max_row[row] = max(grid[row])
            for col in range(len(grid[0])):
                increased += (min(max_row[row], max_col[col]) - grid[row][col])
        
        return increased
