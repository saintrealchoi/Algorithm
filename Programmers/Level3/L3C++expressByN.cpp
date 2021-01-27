#include <string>
#include <vector>
#define MAX 9

using namespace std;

int ans_glb = MAX, num_glb, N_glb; // 전역 변수

void dfs(int cnt, int num) {
    if (cnt >= MAX)
        return;

    if (num == num_glb)
        ans_glb = min(ans_glb, cnt);

    int n = 0;
    for (int i = 0; i < 8; i++) {
        n = (n * 10) + N_glb;
        dfs(cnt + i + 1, num + n);
        dfs(cnt + i + 1, num - n);
        if (num != 0) {
            dfs(cnt + i + 1, num * n);
            dfs(cnt + i + 1, num / n);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    num_glb = number, N_glb = N;
    dfs(0, 0);
    return ((ans_glb == MAX) ? -1 : ans_glb);
}