class Solution {
public:
    unordered_map<char, string> mp;
    vector<string> result;

    void insertKVIntoMap() {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;

        insertKVIntoMap();
        
        string temp;
        solve(0, digits, temp);

        return result;
    }

    void solve(int start, string &str, string &tmp) {
        // base case - once `start` reaches the end of the input `str`
        if(start == str.size()) {
            result.push_back(tmp);
            return;
        }

        char ch = str[start];
        for(char c: mp[ch]) {
            tmp += c;
            
            solve(start+1, str, tmp);

            // backtrack
            tmp.pop_back();
        }
    }
};