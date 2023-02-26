class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """

        # parameters
        rowS, colS = len(matrix), len(matrix[0])
        rFlag, cFlag = False, False

        # start computing

        # search the first row & the first column
        for i in range(colS):
            if not matrix[0][i]:
                rFlag = True
                break
        for i in range(rowS):
            if not matrix[i][0]:
                cFlag = True
                break

        # search for others and convert the corresponding element in the 1st row&column to 0
        for i in range(1, rowS):
            for j in range(1, colS):
                if not matrix[i][j]:
                    matrix[i][0] = matrix[0][j] = 0
        
        # update the zeros correspond to the inside area
        for i in range(1, rowS):
            for j in range(1, colS):
                if ((not matrix[i][0]) or (not matrix[0][j])):
                    matrix[i][j] = 0
    
        # update the the zeros correspond to the outside area
        if rFlag:
            for i in range(colS):
                matrix[0][i] = 0
        if cFlag:
            for i in range(rowS):
                matrix[i][0] = 0
