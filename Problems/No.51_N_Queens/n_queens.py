class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        # check if Qs are valid
        def check_Qs(row, col):
            
            # check toward
            for i in range(row):
                if (nQueens[i][col] == 'Q'):
                    return False
            
            # check top-left -> bottom-right
            i, j = row-1, col-1
            while ((i >= 0) and (j >= 0)):
                if (nQueens[i][j] == 'Q'):
                    return False
                else:
                    i -= 1
                    j -= 1

            # check top-right -> bottom-left
            i, j = row-1, col+1
            while ((i >= 0) and (j < n)):
                if (nQueens[i][j] == 'Q'):
                    return False
                else:
                    i -= 1
                    j += 1

            # all pass
            return True


        # backtrack Queens
        def track_Queens(row):
            if (row == n):
                Queens_set.append(["".join(_) for _ in nQueens])
            else:
                for col in range(n):
                    if check_Qs(row, col):
                        nQueens[row][col] = 'Q'
                        track_Queens(row+1)
                        nQueens[row][col] = '.'


        # parameters
        Queens_set = []
        nQueens = [["." for _ in range(n)] for _ in range(n)]

        # start computing
        track_Queens(0)
        
        return Queens_set
