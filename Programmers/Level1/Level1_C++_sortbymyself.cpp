#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;

bool compare(const string& a, const string& b) {
    if (a[num] == b[num])
        return a < b;
    else
        return a[num] < b[num];

}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
  
    num = n;

    sort(strings.begin(), strings.end(), compare);

    for (int i = 0; i < strings.size(); i++) {
        answer.emplace_back(move(strings[i]));
    }
    return answer;
}