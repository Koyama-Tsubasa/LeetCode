class Solution(object):
    def minFlips(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """

        # check if it is zero matrix
        def CheckZero(matrix):
            for c_i in range(m):
                for c_j in range(n):
                    if matrix[c_i][c_j]:
                        return False
            return True
    

        # parameters
        AllPossibles = []
        checked = []
        checks = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        flip_count, m, n = 0, len(mat), len(mat[0])

        # start computing
        AllPossibles.append(mat)
        checked.append(mat)
        while AllPossibles:
            CheckSize = len(AllPossibles)

            for i in range(CheckSize):
                if CheckZero(AllPossibles[0]):
                    return flip_count
                else:
                    for row in range(m):
                        for col in range(n):
                            currMat = deepcopy(AllPossibles[0])
                            currMat[row][col] = 1 - currMat[row][col]

                            for check in checks:
                                newRow = row + check[0]
                                newCol = col + check[1]
                                if ((0 <= newRow < m) and (0 <= newCol < n)):
                                    currMat[newRow][newCol] = 1 - currMat[newRow][newCol]
                            
                            if (currMat not in checked):
                                AllPossibles.append(currMat)
                                checked.append(currMat)
                AllPossibles.pop(0)
            flip_count += 1
        
        return -1
