class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        int open_count = 0, close_count = 0;

        solve(open_count, close_count, n, temp, res);

        return res;
    }

    void solve(int open_cnt, int close_cnt, int n, string &temp, vector<string> &res) {
        // base case - When string size i.e. `temp.size()` reaches `n+n`
        if(temp.size() == n+n) {
            res.push_back(temp);
            return;
        }

        // if `open_cnt` is less than `n`, insert into the `temp` string
        if(open_cnt < n) {
            temp.push_back('(');
            solve(open_cnt+1, close_cnt, n, temp, res);

            // backtrack
            temp.pop_back();
        }

        // if `close_cnt` is less than `open_cnt`, insert into the `temp` string
        if(close_cnt < open_cnt) {
            temp.push_back(')');
            solve(open_cnt, close_cnt+1, n, temp, res);

            // backtrack
            temp.pop_back();
        }
    }
};