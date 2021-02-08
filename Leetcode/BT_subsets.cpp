class Solution {
public:
    void backTracking(vector<int>& nums, vector<vector<int> >& res,
        vector<int>& subset, int index) {
        res.emplace_back(subset);

        for (int i = index; i < nums.size(); i++) {
            subset.emplace_back(nums[i]);
            backTracking(nums, res, subset, i + 1);
            subset.pop_back();
        }
        return;
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int> > res;

        int index = 0;
        backTracking(nums, res, subset, index);

        return res;
    }
};