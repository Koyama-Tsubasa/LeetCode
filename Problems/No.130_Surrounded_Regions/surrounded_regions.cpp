class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        // parameters
        int m = board.size(), n = board[0].size();
        std::vector<std::pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        std::vector<std::vector<bool>> IsChecked(m, std::vector<bool>(n, false));
        std::queue<std::pair<int, int>> boarderConnected;

        // start computing
        // find the boarder 'O's
        for (int row=0; row<m; row++) {
            for (int col=0; col<n; col++) {
                if ((row == 0) || (row == m-1) || (col == 0) || (col == n-1)) {

                    if (board[row][col] == 'O') boarderConnected.push({row, col});
                    IsChecked[row][col] = true;

                }
            }
        }
        
        // BFS from boundary 'O's
        while (!boarderConnected.empty()) {

            auto [x, y] = boarderConnected.front();
            boarderConnected.pop();
            IsChecked[x][y] = true;

            for (auto &move: moves) {

                int newX = x + move.first;
                int newY = y + move.second;

                if ((0 < newX) && (newX < m) && (0 < newY) && (newY < n)) {
                    if (!IsChecked[newX][newY]) {

                        if (board[newX][newY] == 'O') boarderConnected.push({newX, newY});
                        IsChecked[newX][newY] = true;

                    }
                }

            }

        }

        // convert other 'O's
        for (int row=1; row<m-1; row++) 
            for (int col=1; col<n-1; col++) 
                if (!IsChecked[row][col] && (board[row][col] == 'O'))
                    board[row][col] = 'X';

    }
};
