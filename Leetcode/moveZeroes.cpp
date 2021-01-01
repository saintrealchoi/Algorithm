class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] != 0) {
                swap(nums[index], nums[idx]);
                index++;
            }
        }
    }
};