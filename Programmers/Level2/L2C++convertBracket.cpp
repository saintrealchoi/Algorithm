#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string s) {
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') count++;
        else {
            if (!count) return false;
            count--;
        }
    }

    return true;
}

string recursion(string p) {
    if (p == "") return p;
    string u{};
    string v{};
    int a{}, b{};

    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') a++;
        else b++;

        if (a == b) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u)) return u + recursion(v);

    else {
        string tmp = "(";
        tmp += recursion(v) + ")";
        u = u.substr(1, u.length() - 2);

        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
}

string solution(string p) {
    if (check(p)) return p;
    return recursion(p);
}