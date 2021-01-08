#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer, v;
    for (int i = 1; i < s.size() - 1; i++)
    {
        int sum = 0;
        if (s[i] == '{')
        {
            int idx = i + 1;
            for (int j = idx; j < s.size() - 1; j++)
            {
                if (s[j] == ',')
                {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                }
                if (s[j] == '}')
                {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                    break;
                }
            }
            v.push_back(sum);
        }
    }

    sort(v.begin(), v.end());
    answer.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
        answer.push_back(v[i] - v[i - 1]);
    return answer;
}