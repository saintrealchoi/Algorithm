#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    vector<pair<int, double>> percent;
    map<int, int> stagesClear;
    int pCount = stages.size();

    for (int j = 0; j < stages.size(); j++)
        stagesClear[stages[j]]++;

    for (int i = 1; i <= N; i++) {
        if (!pCount || !stagesClear[i])
            percent.push_back({ i, 0 });
        else
            percent.push_back({ i, (double)stagesClear[i] / pCount });
        pCount -= stagesClear[i];
    }
    sort(percent.begin(), percent.end(), compare);
    for (auto p : percent)
        answer.push_back(p.first);
    return answer;
}