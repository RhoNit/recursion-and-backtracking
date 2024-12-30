class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string output;
        int open = n, close = n;

        solve(open, close, output, res);

        return res;
    }

    void solve(int open, int close, string output, vector<string> &res) {
        // base case
        if(open == 0 and close == 0) {
            res.push_back(output);
            return;
        }

        if(open > 0) {
            // recursive call 1 - Choosing '(' in the output string
            solve(open-1, close, output + '(', res);
        }

        if(close > open) { // as open would be chosen or used first to make the pattern valid.. so open_count left would be lesser than closed_count
            // recursive call 2 - Choosing ')' in the output string
            solve(open, close-1, output + ')', res);
        }
    }
};