#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int temp = 0;
    vector<int> check(lost.size(), 0);
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve[i] = -1;
                lost[j] = -1;
                answer++;
                break;
            }
        }
    }
    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] != -1) {
            for (int j = 0; j < lost.size(); j++) {
                if (check[j] != 1 && abs(lost[j] - reserve[i]) < 2) {
                    answer++;
                    check[j] = 1;
                    break;
                }
            }
        }
    }

    return answer;
}