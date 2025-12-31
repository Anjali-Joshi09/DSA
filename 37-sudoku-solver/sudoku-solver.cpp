class Solution {
public:
    int row[9] = {}, col[9] = {}, box[9] = {};

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx == 81) return true;

        int r = idx / 9;
        int c = idx % 9;

        if (board[r][c] != '.')
            return solve(board, idx + 1);

        int b = (r / 3) * 3 + (c / 3);
        int used = row[r] | col[c] | box[b];

        for (int d = 1; d <= 9; d++) {
            int mask = 1 << d;
            if ((used & mask) == 0) {
                board[r][c] = '0' + d;
                row[r] |= mask;
                col[c] |= mask;
                box[b] |= mask;

                if (solve(board, idx + 1)) return true;
                board[r][c] = '.';
                row[r] ^= mask;
                col[c] ^= mask;
                box[b] ^= mask;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c] - '0';
                    int mask = 1 << d;
                    row[r] |= mask;
                    col[c] |= mask;
                    box[(r / 3) * 3 + (c / 3)] |= mask;
                }
            }
        }
        solve(board, 0);
    }
};
