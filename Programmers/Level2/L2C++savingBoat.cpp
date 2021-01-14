#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int p = 0;
    int q = people.size() - 1;

    sort(people.begin(), people.end());

    while (p < q + 1) {
        if (people[p] + people[q] <= limit) p++;
        q--;
        answer++;
    }

    return answer;
}