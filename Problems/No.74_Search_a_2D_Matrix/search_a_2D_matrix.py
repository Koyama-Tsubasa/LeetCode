class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        # parameters
        rowS, colS = len(matrix), len(matrix[0])
        left, right, mid = 0, rowS*colS-1, None
        r, c = None, None

        # start computing
        while (left <= right):
            
            mid = left + (right-left)//2
            r = mid // colS
            c = mid % colS
                 
            if (matrix[r][c] == target):
                return True
            elif (matrix[r][c] < target):
                left = mid + 1
            else:
                right = mid - 1
        
        return False
