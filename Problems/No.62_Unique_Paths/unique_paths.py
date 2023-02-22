class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        # parameter
        AREA = [[1]*n for i in range(m)]

        # start computing
        for i in range(1, m):
            for j in range(1, n):
                AREA[i][j] = AREA[i-1][j] + AREA[i][j-1]
        
        return AREA[-1][-1]
