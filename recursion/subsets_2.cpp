class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res_set;
        vector<int> output;

        sort(nums.begin(), nums.end());

        solve(nums, output, res_set);

        // create a vector from set elems
        vector<vector<int>> res(res_set.begin(), res_set.end());

        return res;
    }

    void solve(vector<int> nums, vector<int> output, set<vector<int>> &res_set) {
        // base case - When the input array becomes empty
        if(nums.size() == 0) {
            // hashSet to filter out the duplicate elements
            res_set.insert(output);
            return;
        }

        // take out the first elem from the input array
        int first = nums[0];
        nums.erase(nums.begin()); // remove the first elem from the array

        vector<int> output1 = output; // introducing a `output1` vector to include the first elem into it
        output1.push_back(first); // add the `first` elem into it

        // recursive call - Choose the first elem from the input
        solve(nums, output1, res_set);

        // recursive call - Not choosing the first elem from the input
        solve(nums, output, res_set); 
    }
};