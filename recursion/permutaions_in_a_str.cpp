class Solution {
  public:
    vector<string> find_permutation(string s) {
        vector<string> res;
        
        string output = "";
        string remaining = s;
        
        permute(remaining, output, res);
        
        return res;
    }
    
    void permute(string remaining, string output, vector<string> &res) {
        if(remaining.size() == 0) {
            res.push_back(output);
            return;
        }
        
        unordered_map<char, int> mp;
        
        for(int i = 0; i < remaining.size(); i++) {
            // controlled recursion
            if(mp.find(remaining[i]) == mp.end()) {
                mp.insert({remaining[i], 1});
                // mp[remaining[i]] = 1;
                
                string new_output = output + remaining[i];
                string new_remaining = remaining.substr(0, i) + remaining.substr(i+1);
                
                permute(new_remaining, new_output, res);
            }
        }
    }
};