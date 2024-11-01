// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        
        solve(0, s, temp, result);
        
        return result;
    }
    
    void solve(int start, string &str, vector<string> &temp, vector<vector<string>> &result) {
        // base case - once `start` reaches the end of the `str`
        // at that time, we will have `temp` filled with palindromic strings
        // we will insert that lot into `result`
        if(start == str.size()) {
            result.push_back(temp);
            return;
        }
        
        string pal_str;
        for(int i = start; i < str.size(); i++) {
            pal_str += str[i];
            
            if(isPalindromic(pal_str)) {
                temp.push_back(pal_str);
                
                solve(i+1, str, temp, result);
                // backtrack to previous state i.e. especially of `temp`
                temp.pop_back();
            }
        }
    }
    
    bool isPalindromic(string &pal_str) {
        int start = 0, end = pal_str.size()-1;
        while(start < end) {
            if(pal_str[start] != pal_str[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
};