#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int count = 0;
    int idx = 0;

    while(!skill_trees.empty()) {
        string tmpstring = "";
        string s = skill_trees.back();
        skill_trees.pop_back();


        for (int i = 0; i < s.length(); i++) {
            char tmp = move(s[i]);
            for (int j = 0; j < skill.length(); j++) {
                char tmp2 = move(skill[j]);
                if (tmp == tmp2) {
                    tmpstring.push_back(tmp2);
                    break;
                }
            }
        }

        if (skill.substr(0, tmpstring.size()) == tmpstring)
            answer++;
    }

    return answer;
}