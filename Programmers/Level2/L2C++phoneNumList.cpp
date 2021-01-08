#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    return answer;
}

int main() {
    string s = "{{}{4}{}3{}2{}1}";
    int size = s.size();
    for (int i = 0; i < size; i++) {
        s.erase(s.find('{'), 1);
    }
    cout << s;
}