#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool find(string s, string name ,vector<vector<string>> &before) {
    bool answer = false;
    for (int i = 0; i < before.size(); i++) {
        if (before[i][1] == s) {
            answer = true;
            before[i][2] = name;
        }
    }
    return answer;
}

string append(string s, vector<vector<string>>& before) {
    for (int i = 0; i < before.size(); i++) {
        if (before[i][1] == s)
            return before[i][1];
    }
    return "?";
}

void change(string s, string name,vector<vector<string>>& before) {
    for (int i = 0; i < before.size(); i++) {
        if (before[i][1] == s)
            before[i][2] = name;
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> word;
    vector<vector<string>> before;

    for (int i = 0; i < record.size(); i++) {
        vector<string> s;
        int count = 0;
        for (int j = 0; j < record[i].size()+1; j++) {
            if (record[i][j] == ' ' || j==record[i].size()) {
                s.emplace_back(record[i].substr(count, j-count));
                count = j + 1;
            }
        }
        word.emplace_back(s);
    }

    for (int i = 0; i < word.size(); i++) {
        if (word[i][0] == "Enter") {
            if (find(word[i][1],word[i][2], before)) {
                before.emplace_back(word[i]);
                continue;
            }
            else
                before.emplace_back(word[i]);
        }
        else if (word[i][0] == "Leave") {
            word[i].emplace_back(append(word[i][1], before));
            before.emplace_back(word[i]);
        }
        else {
            change(word[i][1],word[i][2], before);
        }
    }
    for (int i = 0; i < before.size(); i++) {
        string s;
        s.append(before[i][2]);
        s.append("님이 ");
        if (before[i][0] == "Enter") s.append("들어왔습니다.");
        else s.append("나갔습니다.");
        answer.emplace_back(s);
    }
   
    return answer;
}
int main() {
    vector<string>record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    solution(record);
}