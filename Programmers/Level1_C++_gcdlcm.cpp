#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b, int c) {
    return a * b / c;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.emplace_back(gcd(n, m));
    answer.emplace_back(lcm(n, m, answer[0]));
    return answer;
}
