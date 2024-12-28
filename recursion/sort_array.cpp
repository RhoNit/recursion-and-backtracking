class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums);

        return nums;
    }

    void sort(vector<int>& nums) {
        // base case - If array size reduces to 1, the array is already sorted with one element
        if(nums.size() == 1) {
            return;
        }

        int elem = nums[nums.size()-1];
        nums.pop_back();

        // recursive call
        sort(nums);

        insertElem(nums, elem);

    }

    void insertElem(vector<int> &nums, int elem) {
        // base case - When the array is having size 0, then we can insert that elem
        // or when the elem is greater than the last element of that array
        if(nums.size() == 0 or nums[nums.size()-1] <= elem) {
            nums.push_back(elem);
            return;
        }

        int temp = nums[nums.size()-1];
        nums.pop_back();

        // recursive call
        insertElem(nums, elem);

        nums.push_back(temp);
    }
};