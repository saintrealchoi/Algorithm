#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    int front,end,num;
    for (int i = 0; i < commands.size(); i++) {
        front = move(commands[i][0]);
        end = move(commands[i][1]);
        num = move(commands[i][2]);

        for (int j = front; j < end+1; j++) {
            tmp.emplace_back(array[j - 1]);
        }
        sort(tmp.begin(),tmp.end());
        answer.emplace_back(tmp[num - 1]);
        tmp.clear();
    }

    return answer;
}