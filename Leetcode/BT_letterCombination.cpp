class Solution {
public:

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxSubArray(vector<int>& nums) {
        vector<int> tmp;
        vector<int> idx;
        tmp.emplace_back(move(nums[0]));
        int max = -99999999;

        for (int i = 1; i < nums.size(); i++) {
            if (tmp.back() + nums[i] < nums[i]) {
                tmp.emplace_back(nums[i]);
            }
            else {
                tmp.emplace_back(tmp.back() + nums[i]);
            }

        }

        for (int i = 0; i < tmp.size(); i++) {
            if (max < tmp[i])
                max = tmp[i];
        }


        return max;
    }
};