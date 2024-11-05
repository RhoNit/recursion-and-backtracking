// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> temp;

        solve(0, temp, board, n);

        return ans;
    }

    void solve(int col_idx, vector<int> &temp, vector<vector<int>> &board, int n) {
        // base case - When `col_idx` reaches the end of the column of the board
        if(col_idx == n) {
            ans.push_back(temp);
            return;
        }

        // keeping `col_idx` as it is, we'll iterate over the rows of a specific column
        for(int row_idx = 0; row_idx < n; row_idx++) {
            // check if we can place a queen in the current cell
            if(check(row_idx, col_idx, board, n)) {
                board[row_idx][col_idx] = 1;
                temp.push_back(row_idx+1);

                solve(col_idx+1, temp, board, n);

                // backtrack - Undo the changes
                temp.pop_back();
                board[row_idx][col_idx] = 0;
            }
        }
    }

    bool check(int row_idx, int col_idx, vector<vector<int>> &board, int n) {
        // left side case check - (row, 0) to (row, col-1)
        for(int i = 0; i < col_idx; i++) {
            if(board[row_idx][i] == 1) { return false; }
        }

        // upper left diagonal case check - (0,0) to (row-1, col-1)
        int i = row_idx, j = col_idx;
        while(i >= 0 and j >= 0) {
            if(board[i][j] == 1) { return false; }
            i--;
            j--;
        }

        // lower left diagonal case check - (n-1, 0) to (row+1, col-1)
        int x = row_idx, y = col_idx;
        while(x < n and y >= 0) {
            if(board[x][y] == 1) { return false; }
            x++;
            y--;
        }

        return true;
    }
};