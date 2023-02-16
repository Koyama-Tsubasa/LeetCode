class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        # parameter
        spiral_order = []

        # start computing
        while matrix:

            # Top Row
            spiral_order += matrix.pop(0)
            
            # Right Column
            if matrix and matrix[0]:
                for row in matrix:
                    spiral_order.append(row.pop())
            
            # Bottom Row
            if matrix:
                spiral_order += matrix.pop()[::-1]
            
            # Left Column
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    spiral_order.append(row.pop(0))

        return spiral_order
