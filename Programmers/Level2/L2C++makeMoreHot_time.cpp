#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    while (scoville.size() > 1) {
        int tmp,tmp2;
        sort(scoville.begin(), scoville.end(), greater<int>());

        tmp = move(scoville.back());
        scoville.pop_back();
        tmp2 = move(scoville.back());

        scoville.back() = tmp + 2 * tmp2;

        sort(scoville.begin(), scoville.end(), greater<int>());

        if (scoville.back() >= K)
            return ++answer;

        answer++;

    }

    if (scoville[0] >= K)
        return 0;

    return -1;
}