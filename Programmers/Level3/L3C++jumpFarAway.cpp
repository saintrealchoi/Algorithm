#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> sol = { 1,1 };
    for (int i = 2; i <= n; i++) {
        long long tmp1 = move(sol[i - 1]);
        long long tmp2 = move(sol[i - 2]);
        sol.emplace_back(tmp1 + tmp2);
        sol.back() %= 1234567;
    }

    return sol.back();
}