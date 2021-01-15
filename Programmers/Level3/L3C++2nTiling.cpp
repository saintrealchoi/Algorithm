#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> sol = { 1,1 };
    for (int i = 2; i <= n; i++) {
        int tmp1 = move(sol[i - 1]);
        int tmp2 = move(sol[i - 2]);
        sol.emplace_back(tmp1 + tmp2);
        sol.back() %= 1000000007;
    }

    return sol[n];
}