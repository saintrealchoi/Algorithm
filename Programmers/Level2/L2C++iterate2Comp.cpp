#include <string>
#include <vector>
#include <cmath>

using namespace std;

int zeros = 0;
string ret = "";
int ans = 0;

string findZero(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            ret.push_back(s[i]);
        else
            zeros++;
    }
    return ret;
}

string change(int s) {
    string changeS = "";
    while (s > 1) {
        changeS.append(to_string(s % 2));
        s /= 2;
    }
    changeS.append(to_string(1));
    reverse(changeS.begin(), changeS.end());

    return changeS;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    
    while (s == "1") {
        string tmp;
        s = findZero(s);
        ret = "";
        s = change(s.length());
        count++;
    }

    answer.emplace_back(zeros);
    answer.emplace_back(count);

    return answer;
}
