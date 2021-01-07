#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> p;
    vector<int> s;
    int count = 0;
    int tmp;

    int size = progresses.size();
    for (int i = 0; i < size; i++) {
        tmp = progresses.back();
        p.emplace_back(tmp);
        progresses.pop_back();
        tmp = speeds.back();
        s.emplace_back(tmp);
        speeds.pop_back();
    }
    while (!p.empty()) {
        for (int i = 0; i < size; i++) {
            p[size - i - 1] += s[size - i - 1];
        }
        while (p.back() > 99) {
            p.pop_back();
            s.pop_back();
            count++;
        }
        if (size != p.size())size = p.size();
        if (count > 0) {
            answer.emplace_back(count);
            count = 0;
        }
    }

    return answer;
}