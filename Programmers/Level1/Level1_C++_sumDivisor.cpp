#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (n % (i + 1) == 0) answer += (i + 1);
    }

    return answer;
}