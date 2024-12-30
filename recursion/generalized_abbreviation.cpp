class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string output;
        int count = 0;

        solve(word, output, count, res);

        return res;
    }

    void solve(string word, string output, int count, vector<string> &res) {
        // base case
        if(word.size() == 0) {
            if(count == 0) {
                res.push_back(output); // don't abbreviate case
            } else {
                res.push_back(output+to_string(count)); // abbreaviate case
            }
            return;
        }

        // take out the first elem
        char first = word[0];
        word.erase(word.begin()); // remove the first elem from the input string

        // recursive call 1 - don't choose the char (abbreviate the char)
        solve(word, output, count+1, res);

        // recursive call 2 - choose the char (don't abbreviate the char)
        if(count == 0) {
            // case - when count is 0 - We simply can do `output += count`
            solve(word, output+first, 0, res);
        } else {
            // case - when count > 0, we will have to add count to the output before adding first char
            solve(word, output+to_string(count)+first, 0, res);
        }
    }
};