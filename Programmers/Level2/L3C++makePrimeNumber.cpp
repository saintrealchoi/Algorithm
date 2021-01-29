#include <algorithm>
#include <vector>
#include <string>

using namespace std;


vector<vector<int> > Combination(vector<int> container, int r) {
    int n = container.size();
    if (n < r) return {};
    if (r < 0) return {};

    vector<vector<int>> to;
    vector<int> tmp(r);

    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);
    int idx;
    do {
        idx = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                tmp[idx++] = *(container.begin() + i);
            }
        }
        to.emplace_back(tmp);
    } while (next_permutation(v.begin(), v.end()));

    return to;
}

bool chk(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> ans;
    vector<vector<int>> permutation = Combination(nums, 3);

    for (int i = 0; i < permutation.size(); i++) {
        int tmp = permutation[i][0] + permutation[i][1] + permutation[i][2];
        ans.emplace_back(tmp);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (chk(ans[i])) answer += 1;
    }

    return answer;
}