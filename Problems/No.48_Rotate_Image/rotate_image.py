class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        
        # parameters
        size = len(matrix)
        r_num = size - 1
        
        # start compute
        for i in range(size//2):
            for j in range(r_num):
                temp = matrix[i][i+j]
                matrix[i][i+j] = matrix[size-1-i-j][i]
                matrix[size-1-i-j][i] = matrix[size-1-i][size-1-i-j]
                matrix[size-1-i][size-1-i-j] = matrix[i+j][size-1-i]
                matrix[i+j][size-1-i] = temp
            r_num -= 2
        
        return
