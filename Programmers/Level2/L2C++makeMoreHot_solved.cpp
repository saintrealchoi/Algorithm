#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.size() > 1) {
        int tmp = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();

        pq.push(tmp + tmp2 * 2);

        if (pq.top() >= K)
            return ++answer;

        answer++;
    }

    if (pq.top() >= K)
        return 0;
    
    return -1;
}