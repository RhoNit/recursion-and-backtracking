class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(0, target, candidates, temp, result);

        return result; 
    }

    void solve(int start, int target, vector<int> candidates, vector<int> &temp, vector<vector<int>> &result) {
        // base case - When `target` is achieved
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        
        // base case - When `start` reaches the end of the original array i.e. `candidates`
        if(start == candidates.size()) return;

        // if current array element is less than or equal to `target` element,
        // then only we would pick that element
        if(candidates[start] <= target) {
            temp.push_back(candidates[start]);
            
            // one recursive call - When we would choose to pick the current element repetitively
            solve(start, target-candidates[start], candidates, temp, result);

            // backtrack
            temp.pop_back();
        }

        // another recursive call - When we would not pick the current element and
        // would move the `start` to the next index
        solve(start+1, target, candidates, temp, result);
    }
};