#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer = s;
    int ch = 0;

    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] == ' ') {
            ch = 0;
            continue;
        }

        if (ch % 2 == 0) {
            if (answer[i] >= 'a' && answer[i] <= 'z')
                answer[i] = answer[i] - 'a' + 'A';
        }
        else {
            if (answer[i] >= 'A' && answer[i] <= 'Z')
                answer[i] = answer[i] - 'A' + 'a';
        }
        ch++;
    }

    return answer;
}