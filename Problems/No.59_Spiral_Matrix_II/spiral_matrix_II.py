class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """

        # parameters
        spiral_matrix = [[0] * n for i in range(n)]
        c_start, c_end, r_start, r_end = 0, n-1, 0, n-1
        count = 1

        # start computing
        while (count <= n*n):

            # Top Row
            for i in range(c_start, c_end+1):
                spiral_matrix[r_start][i] = count
                count += 1
            
            # Right Column
            for i in range(r_start+1, r_end+1):
                spiral_matrix[i][c_end] = count
                count += 1
            
            # Bottom Row
            for i in range(c_end-1, c_start-1, -1):
                spiral_matrix[r_end][i] = count
                count += 1
            
            # Left Column
            for i in range(r_end-1, r_start, -1):
                spiral_matrix[i][c_start] = count
                count += 1
            
            # update parameters
            r_start += 1
            c_start += 1
            r_end -= 1
            c_end -= 1
    
        return spiral_matrix
