class Solution {
public:
    void backTracking(string& str, int pos, int stage, string cur, vector<string>& res) {
        if (stage == 4) {
            if (pos == str.length())
                res.emplace_back(cur);
            return;
        }

        string now;
        for (int ed = pos, v = 0; ed < str.length(); ed++) {
            now += str[ed];
            if (stoi(now) > 255 || (now.length() > 1 && now[0] == '0'))
                break;
            if (stage == 0)
                backTracking(str, ed + 1, stage + 1, cur + now, res);
            else
                backTracking(str, ed + 1, stage + 1, cur + "." + now, res);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backTracking(s, 0, 0, "", res);
        return res;
    }
};