// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k) {
        string max_str = str;
        solve(str, k, 0, max_str);
        return max_str;
    }
    
    void solve(string &s, int k, int start, string &max_str) {
        // base case - When the `start` would reach the end of the `s`
        // and when swap-opportunity i.e. k becomes nil or zero
        if(start == s.size()-1 or k == 0) {
            // just stop the recursion
            return;
        }
        
        char max_digit = s[start];
        // find maximum digit except `s[i]` in the string
        for(int i = start+1; i < s.size(); i++) {
            if(s[i] > max_digit) { max_digit = s[i]; }
        }

        // as we don't have unlimited swaps, 
        // we would avoid self swaps and swaps where remaining digits are smaller than the current digit
        for(int i = start+1; i < s.size(); i++) {
            if(s[start] < s[i] and s[i] == max_digit) {
                swap(s[start], s[i]);
                
                // if current form on string i.e. number is larger than the prev one,
                // then update the maximum number
                if(s.compare(max_str) > 0) { max_str = s; }
                
                solve(s, k-1, start+1, max_str);
                
                // backtracking
                swap(s[start], s[i]);
            }
        }
        // this recursive call is for condition when no swaps have been done
        // at the current position and we want to move to the next position 
        // without decreasing `k`
        // e.g. s = "721"
        solve(s, k, start+1, max_str);
    }
};