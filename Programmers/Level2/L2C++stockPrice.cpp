#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    for (int i = 0; i < prices.size(); i++) {
        int tmp = move(prices[i]);
        for (int j = i + 1; j < prices.size(); j++) {
            int tmpj = move(prices[j]);
            answer[i]++;
            if (tmp > tmpj)
                break;
        }
    }
    return answer;
}