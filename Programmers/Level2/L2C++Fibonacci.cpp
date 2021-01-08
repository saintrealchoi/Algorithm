#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> v;
    v.emplace_back(0);
    v.emplace_back(1);
    for (int i = 0; i < n; i++) {
        int tmp1 = move(v[i]);
        int tmp2 = move(v[i + 1]);
        v.emplace_back((tmp1 + tmp2) % 1234567);
    }
    answer = v[n];
    return answer;
}