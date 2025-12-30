class Solution {
public:
    bool isMagic(vector<vector<int>>& arr, int row, int col) {
        vector<int> freq(10, 0);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int x = arr[i][j];
                if (x < 1 || x > 9 || freq[x]++) return false;
            }
        }

        int sum = arr[row][col] + arr[row][col+1] + arr[row][col+2];

        for (int i = row; i < row + 3; i++)
            if (arr[i][col] + arr[i][col+1] + arr[i][col+2] != sum)
                return false;

        for (int j = col; j < col + 3; j++)
            if (arr[row][j] + arr[row+1][j] + arr[row+2][j] != sum)
                return false;

        if (arr[row][col] + arr[row+1][col+1] + arr[row+2][col+2] != sum) return false;
        if (arr[row][col+2] + arr[row+1][col+1] + arr[row+2][col] != sum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
