class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> temp;

        solve(0, s, temp, result);

        return result;
    }

    void solve(int start, string &s, vector<string> &temp, vector<string> &result) {
        // base case - When `start` reaches the end of the string
        if(start == s.size() and temp.size() == 4) {
            string helper = "";
            for(int j = 0; j < temp.size(); j++) {
                helper += temp[j];

                if(j != temp.size()-1) {
                    helper += '.';
                }
            }
            result.push_back(helper);
            return;
        }

        // Optimization (IMPORTANT) - We need to stop as soon as we have 4 segments inside our `temp` vector
        // even if the string hasn't been processed completely
        if(temp.size() >= 4) {
            return;
        }

        string curr_str = "";
        for(int i = start; i < s.size(); i++) {
            // check - Whether s[i] is beyond ['0', '9']
            // that means, it could be '@' (ASCII value is 64) or other special char
            // although this TC hasn't been handled here (not that important as of now)
            if(s[i] - '0' > 9) {
                continue;
            }

            curr_str += s[i];
            // check - Escaping the leading zeros i.e. '001' is not acceptable
            if (curr_str.size() > 1 and curr_str[0] == '0') {
                continue;
            }

            // extra check (IMPORTANT) - Verify if a segment length lesser than or equal to 3
            // cause more than 3 length segment is not been handled in the question
            // so before converting it to integer, we must have to check this case
            if(curr_str.size() > 3) {
                continue;
            }

            int curr_str_num = stoi(curr_str);

            if(curr_str_num >= 0 and curr_str_num <= 255) {
                temp.push_back(curr_str);

                // recursive call
                solve(i+1, s, temp, result);

                // backtrack
                temp.pop_back();
            }
        }
    }
};