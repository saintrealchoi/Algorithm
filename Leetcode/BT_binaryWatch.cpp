

class Solution {
private:
    const int totalBits = 10;
    const int offset = 4;
    vector<string> solution;

    bool isTimeValid(int hour, int minute) {
        return hour < 12 && minute < 60;
    }

    void bt(const pair<int, int>& time, int start, int remaining) {
        if (remaining == 0) {
            string answer = to_string(time.first) + ":" + (time.second < 10 ? "0" : "")
                + to_string(time.second);
            solution.emplace_back(answer);
            return;
        }

        for (int i = start; i < totalBits; ++i) {
            auto shift = (i < offset) ? i : i - offset;
            auto hours = time.first + ((i < offset) ? (1 << shift) : 0);
            auto mins = time.second + ((i < offset) ? 0 : (1 << shift));

            if (!isTimeValid(hours, mins)) continue;

            bt({ hours, mins }, i + 1, remaining - 1);
        }
    }

public:
    vector<string> readBinaryWatch(int num) {
        bt({ 0, 0 }, 0, num);
        return solution;
    }
};