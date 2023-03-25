class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """

        # parameters
        m, n = len(board), len(board[0])
        moves = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        IsChecked = [[False] * n for _ in range(m)]
        boarderConnected = []

        # start computing
        # find the boarder 'O's
        for row in range(m):
            for col in range(n):
                if ((row == 0) or (row == m-1) or (col == 0) or (col == n-1)):
                    if (board[row][col] == 'O'):
                        boarderConnected.append([row, col])
                    IsChecked[row][col] = True
        
        # BFS from boundary 'O's
        while boarderConnected:
            [x, y] = boarderConnected.pop(0)
            IsChecked[x][y] = True

            for move in moves:
                newX = x + move[0]
                newY = y + move[1]

                if ((0 < newX < m) and (0 < newY < n)):
                    if not IsChecked[newX][newY]:
                        if (board[newX][newY] == 'O'):
                            boarderConnected.append([newX, newY])
                        IsChecked[newX][newY] == True
        
        # convert other 'O's
        for row in range(1, m-1):
            for col in range(1, n-1):
                if (not IsChecked[row][col] and (board[row][col] == 'O')):
                    board[row][col] = 'X'

        
