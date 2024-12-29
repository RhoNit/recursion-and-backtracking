class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string output = "";
        permute(s, output, res);

        return res;
    }

    void permute(string s, string output, vector<string> &res) {
        // base case
        if(s.size() == 0) {
            res.push_back(output);
            return;
        }

        // take out the first element
        char first_char = s[0];
        s.erase(s.begin());

        permute(s, output + first_char, res); // recursive call as it is.. this will help us process the numeric chars

        if(isalpha(first_char)) {
            first_char = islower(first_char) ? toupper(first_char) : tolower(first_char);
            permute(s, output + first_char, res);
        }

    }
};