class Solution {
public:

    // check if Qs are valid
    bool check_Qs(int n, std::vector<std::string> &Qs, int row, int col) {

        // check toward
        for (int i=0; i<row; i++) if (Qs[i][col] == 'Q') return false;

        // check top-left -> bottom-right
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) if (Qs[i][j] == 'Q') return false;

        // check top-right -> bottom-left
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) if (Qs[i][j] == 'Q') return false;

        // all pass
        return true;

    }

    // backtrack Queens
    void track_Queens(int n, std::vector<std::vector<std::string>> &Qs_set, std::vector<std::string> &Qs, int row) {

        if (row == n) Qs_set.push_back(Qs);
        else {

            for (int col=0; col<n; col++) {
                if (check_Qs(n, Qs, row, col)) {

                    Qs[row][col] = 'Q';
                    track_Queens(n, Qs_set, Qs, row+1);
                    Qs[row][col] = '.';

                }
            }

        }

    }

    vector<vector<string>> solveNQueens(int n) {
        
        // parameters
        std::vector<std::vector<std::string>> Queens_set;
        std::vector<std::string> nQueens(n, std::string(n, '.'));

        // start computing
        track_Queens(n, Queens_set, nQueens, 0);

        return Queens_set;

    }
};
