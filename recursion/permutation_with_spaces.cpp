// https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

class Solution {
  public:

    vector<string> permutation(string s) {
        vector<string> res;
        
        string output = "";
        // take out the first element i.e. 'A' from "ABC"
        output += s[0];
        s.erase(s.begin());
        
        permuteHelper(s, output, res);
        
        return res;
    }
    
    void permuteHelper(string s, string output, vector<string> &res) {
        // base case
        if(s.size() == 0) {
            res.push_back(output);
            return;
        }
        
        string output1 = output + ' ' + s[0]; // add element with a space
        string output2 = output + s[0]; // without adding space
        
        // remove the first element i.e. 'B' here from "BC"
        s.erase(s.begin());
        
        permuteHelper(s, output1, res);
        permuteHelper(s, output2, res);
    }
};