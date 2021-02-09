class Solution {
public:
    void backTracking(vector<vector<int>>& v, vector<int>& nums, int start) {
        if (start == nums.size()) {
            v.emplace_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backTracking(v, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>v;
        backTracking(v, nums, 0);
        return v;
    }
};