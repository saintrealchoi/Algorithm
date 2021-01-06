#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    char h = ' ';
    for (char c : s) {
        if ('A' <= c && c <= 'Z') h = 'A';
        else if ('a' <= c && c <= 'z') h = 'a';
        if (c != ' ')
            c = (c + n - h) % 26 + h;
        answer.push_back(c);
    }
    return answer;
}