class Solution {
public:
    int climbStairs(int n) {
        vector<int> v = { 1,2 };
        for (int i = 2; i < n; i++) {
            int tmp = v[i - 1] + v[i - 2];
            v.emplace_back(tmp);
        }
        return v[n - 1];
    }
};