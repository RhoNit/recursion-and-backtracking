// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution {
  public:
    vector<string> find_permutation(string s) {
        vector<string> res;
        permute(s, 0, res);
        return res;
    }
    
    void permute(string &str, int start, vector<string> &res) {
        // base condition - when `start` reaches the end of the string
        // this means we have processed the whole string and stored
        // every possible permutations into the `res` vector
        if(start == str.size()) {
            res.push_back(str);
            return;
        }
        
        unordered_map<char, bool> mp;
        
        for(int i = start; i < str.size(); i++) {
            // if we encounter a repeated `char`,
            // then we will skip the process and will continue for next `char` in `str`
            if(mp.find(str[i]) == mp.end()) {
                mp[str[i]] = true;
                swap(str[i], str[start]);
                permute(str, start+1, res);
                
                // backtrack - revert the values as before
                // as we would be expecting the previous call stack string
                // to process the string further (left over for loop execution)
                swap(str[i], str[start]);
            }
        }
    }
};