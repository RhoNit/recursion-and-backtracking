class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;

        solve(nums, output, res);

        return res;
    }

    void solve(vector<int> nums, vector<int> output, vector<vector<int>> &res) {
        // base case
        if(nums.size() == 0) {
            res.push_back(output);
            return;
        }

        // take out the first element from the input array
        int first = nums[0];
        nums.erase(nums.begin()); // erase the first elem

        vector<int> output1 = output;
        output1.push_back(first);

        // recursive call - choosing the first elem from the input array
        solve(nums, output1, res);

        // recursive call - not choosing the first elem from input array
        solve(nums, output, res);
    }
};