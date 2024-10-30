// https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1

class Solution {
  public:
    vector<int> increasingNumbers(int n) {
        vector<int> result;
        vector<int> vec;
        
        if(n == 1) {
            for(int i = 0; i <= 9; i++) { 
                result.push_back(i); 
            }
            return result;
        }
        
        solve(n, vec, result);
        
        return result;
    }
    
    void solve(int n, vector<int> &vec, vector<int> &res) {
        int ans = 0;
        // base case - When `n` decreases and reaches 0
        // we would push_back() digit into `temp` vector one by one
        // and during each push_back(), `n` i.e. remaining_digits would get decremented by one
        // so, we would have to stop the recursion as soon as `n` hits 0 or
        // we pushed n-number of digits into the `temp` vector
        if(n == 0) {
            for(int i = 0; i < vec.size(); i++) {
                ans = ans*10 + vec[i];
            }
            res.push_back(ans);
            return;
        }
        
        for(int i = 1; i <= 9; i++) {
            if(vec.size() == 0 or i > vec[vec.size()-1]) {
                vec.push_back(i);
                
                solve(n-1, vec, res);
                
                // backtracking - e.g. current state is 45, to consider digits like 6, 7, 8 and 9,
                // we have to restore back to previous state
                // |4|5| -> |4| |
                vec.pop_back();
            }
        }
    }
};