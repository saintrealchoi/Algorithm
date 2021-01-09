#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        string tmp = "";
        if (s[i] == '-') {
            i++;
            while (s[i] != ' ') {
                tmp.push_back(s[i]);                
                i++;
                if (s[i] == NULL) {
                    i--;
                    break;
                }
                
            }
            v.emplace_back(stoi(tmp) * -1);
        }

        else if (s[i] == ' ') continue;

        else  {
            while (s[i] != ' ') {
                tmp.push_back(s[i]);
                i++;
            }
            v.emplace_back(stoi(tmp));
        }
    }

    sort(v.begin(), v.end());

    answer.append(to_string(v[0]));
    answer.append(" ");
    answer.append(to_string(v.back()));

    return answer;
}