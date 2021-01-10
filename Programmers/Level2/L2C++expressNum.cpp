#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    int find = 0;
    while (true) {
        for (int i = start; i < n + 1; i++) {
            find += i;
            if (find == n) {
                answer++;
                break;
            }
            if (find > n) {
                break;
            }
        }
        start += 1;
        find = 0;
        if (start == n) {
            answer++;
            break;
        }
    }


    return answer;
}