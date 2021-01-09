#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int div, rest;
    div = n;
    while (n > 3) {
        rest = n % 3;
        n /= 3;

        if (rest == 0) {
            answer.append(to_string(4));
            n--;
        }
        else answer.append(to_string(rest));
    }

    if (n == 3) answer.append(to_string(4));
    else answer.append(to_string(n));

    reverse(answer.begin(), answer.end());

    return answer;
}