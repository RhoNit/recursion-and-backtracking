class Solution {
public:
    int totalNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        int count = 0;

        solve(0, temp, count, n);

        return count;
    }

    void solve(int col_idx, vector<string> &temp, int &count, int n) {
        // base case - When `col_idx` reaches the end of the column of the board
        if(col_idx == n) {
            count++;
            return;
        }

        // keeping `col_idx` as it is, we'll iterate over the rows of a specific column
        for(int row_idx = 0; row_idx < n; row_idx++) {
            // check if we can place a queen in the current cell
            if(check(row_idx, col_idx, temp, n)) {
                temp[row_idx][col_idx] = 'Q';

                solve(col_idx+1, temp, count, n);

                // backtrack - Undo the changes
                temp[row_idx][col_idx] = '.';
            }
        }
    }

    bool check(int row_idx, int col_idx, vector<string> &temp, int n) {
        // left side case check - (row, 0) to (row, col-1)
        for(int i = 0; i < col_idx; i++) {
            if(temp[row_idx][i] == 'Q') { return false; }
        }

        // upper left diagonal case check - (0,0) to (row-1, col-1)
        int i = row_idx, j = col_idx;
        while(i >= 0 and j >= 0) {
            if(temp[i][j] == 'Q') { return false; }
            i--;
            j--;
        }

        // lower left diagonal case check - (n-1, 0) to (row+1, col-1)
        int x = row_idx, y = col_idx;
        while(x < n and y >= 0) {
            if(temp[x][y] == 'Q') { return false; }
            x++;
            y--;
        }

        return true;
    }
};