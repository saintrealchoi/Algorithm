#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int c = 0;

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int tmp = move(arr[0]);

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size()-1; i++) {
        int tmp2 = move(arr[i + 1]);
        tmp = lcm(tmp,tmp2);
    }


    return tmp;
}