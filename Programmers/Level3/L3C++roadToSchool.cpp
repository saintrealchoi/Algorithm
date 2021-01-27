#include <string>
#include <vector>

using namespace std;
const int MAX = 101;

int solution(int m, int n, vector<vector<int>> puddles) {
    int check[MAX][MAX] = { 0, };
    int ans[MAX][MAX];

    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][1];
        int y = puddles[i][0];
        check[x][y] = 1;
    }

    ans[1][0] = 1;

    for (int i = 1; i <  n +1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (check[i][j] == 1) ans[i][j] = 0;
            else ans[i][j] = (ans[i - 1][j] + ans[i][j - 1]) % 1000000007;
        }
    }
    return ans[n][m]
}