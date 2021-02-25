class Solution {
public:
    int size = 0;

    void BT(vector<string>& arr, string temp, int l, int r) {
        if (temp.size() == size * 2) {
            arr.emplace_back(temp);
            return;
        }

        if (r < size) BT(arr, temp + '(', l, r + 1);
        if (l < size && l < r) BT(arr, temp + ')', l + 1, r);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        size = n;

        BT(arr, "", 0, 0);

        return arr;
    }
};