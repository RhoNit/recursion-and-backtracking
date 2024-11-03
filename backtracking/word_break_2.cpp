// https://www.geeksforgeeks.org/problems/word-break-part-23249/0

class Solution {
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        vector<string> result;
        vector<string> temp;
        unordered_map<string, bool> mp;

        for(int i = 0; i < n; i++) {
            mp.insert({dict[i], true});
        }

        solve(0, mp, s, temp, result);

        return result;
    }

    void solve(int start, unordered_map<string, bool> &mp, string &str, vector<string> &tmp, vector<string> &res) {
        // base case - When `start` hits the end of `str`
        if(start == str.size()) {
            // here we have to segregate each string of `tmp` by a whitespace
            // and then will cumulatively insert the whole `tmp` content into the final `res` vector using a string named `segregated_string_member`
            string segregated_string_member = "";
            for(int idx = 0; idx < tmp.size(); idx++) {
                // `segregated_string_member` -> "cat"
                segregated_string_member += tmp[idx];

                // just a check to add whitespace after each member value of `tmp` vector till last position
                if(idx != tmp.size()-1) {
                    // added a whitespace after each string member of the tmp till iterator reached the last position
                    // at or after last index, we don't have to add any whitespace
                    segregated_string_member += " ";
                }
            }
            res.push_back(segregated_string_member);
            return;
        }

        string curr_str = "";
        for(int i = start; i < str.size(); i++) {
            curr_str += str[i];

            // check if the `curr_str` is a key inside the map `mp`
            if(mp.find(curr_str) != mp.end()) {
                // insert this `curr_str` into `tmp` vector
                // e.g. tmp -> |"cat"|
                // also now `i` = 2
                tmp.push_back(curr_str);

                // recursive call - check the same things written above
                // from `i = i+1` i.e. `i` = 3 or `start` = 3
                solve(i+1, mp, str, tmp, res);

                // backtrack to previous state so that we can check further combinations for each partition untill we reaches the end of the original string
                // e.g. to check for `cat` if there can be other possible combination words
                // like `cats` which may present in the map `mp`
                tmp.pop_back();
            }
        }
    }
};