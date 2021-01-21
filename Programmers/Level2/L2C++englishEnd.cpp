#include <string>
#include <vector>
using namespace std;

vector<string> set;

bool alreadyEx(string v) {
    for (int i = 0; i < set.size(); i++) {
        if (!v.compare(set[i])) {
            return true;
        }
    }
    return false;
}


vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    int idx = 0;
    int size = words.size();
    char front, end;
    char prev[2];
    prev[1] = words[0].front();

    while (idx < size) {
        for (int i = 0; i < n; i++, idx++) {
            front = words[idx].front();
            end = words[idx].back();
            if (front == prev[1]) {
                if (alreadyEx(words[idx])) {
                    answer[0] = i + 1;
                    answer[1] = idx / n + 1;
                    return answer;
                }
                else {
                    set.emplace_back(words[idx]);
                    prev[0] = front;
                    prev[1] = end;
                }
            }
            else {
                answer[0] = i + 1;
                answer[1] = idx / n + 1;
                return answer;
            }
        }
    }

    return answer;
}