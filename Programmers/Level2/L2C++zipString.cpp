#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    vector<int> cd;

    for (int i = 1; i < len; i++) {
        cd.emplace_back(i);
    }
    while (!cd.empty()) {
        int count = 0;
        int idx = cd.back();
        int num = int(len / idx);
        int tmp = len;
        cd.pop_back();

        for (int i = 0; i < num; i++) {
            if (s.substr(i * idx, idx) == s.substr(i * idx + idx, idx)) {

                if (count == 0) {
                    count += 1;
                    tmp -= (idx - 1);
                }
                else {
                    count += 1;
                    if (count == 9) tmp++;
                    if (count == 99) tmp++;
                    if (count == 999) tmp++;
                    tmp -= idx;
                }
            }
            else
                count = 0;
        }

        if (tmp < answer)
            answer = tmp;
    }
    return answer;
}