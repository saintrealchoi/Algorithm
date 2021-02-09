class Solution {
public:
    void backTracking(vector<vector<int>>& v, vector<int>& candidates,
        vector<int>& subset, int index, int target) {
        if (target == 0) {
            v.emplace_back(subset);
            return;
        }
        else if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            int tmp = move(candidates[i]);
            subset.emplace_back(tmp);
            backTracking(v, candidates, subset, i, target - tmp);
            subset.pop_back();

        }
        return;
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int>subset;
        int index;
        backTracking(v, candidates, subset, index, target);
        return v;
    }
};


