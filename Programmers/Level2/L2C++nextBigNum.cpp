#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert(int n) {
    string s;
    while (n > 0) {
        s.append(to_string(n % 2));
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int solution(int n) {
    int nOne = 0;
    string s;

    s = convert(n);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') nOne++;
    }

    while (true) {
        int one = 0;

        n += 1;
        s = convert(n);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') one++;
        }
        if (one == nOne)
            break;
    }

    return n;
}