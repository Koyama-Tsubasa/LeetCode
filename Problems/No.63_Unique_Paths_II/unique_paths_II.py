class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """

        # parameters
        rowS = len(obstacleGrid)
        colS = len(obstacleGrid[0])
        AREA = [[0]*colS for i in range(rowS)]

        # start computing

        # the first row
        for i in range(colS):
            if obstacleGrid[0][i]:
                break
            else:
                AREA[0][i] = 1
        
        # the first column
        for i in range(rowS):
            if obstacleGrid[i][0]:
                break
            else:
                AREA[i][0] = 1

        # other areas
        for i in range(1, rowS):
            for j in range(1, colS):
                if not obstacleGrid[i][j]:
                    AREA[i][j] = AREA[i-1][j] + AREA[i][j-1]
                else:
                    continue
        
        return AREA[-1][-1]
