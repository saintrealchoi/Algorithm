#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int>tmp{ yellow,1 };
    int idx;

    for (int i = 2; i < yellow; i++) {
        if (yellow % i == 0) {
            if (tmp.back() == i) {
                break;
            }
            tmp.emplace_back(i);
            tmp.emplace_back(yellow / i);
        }
    }
    sort(tmp.begin(), tmp.end());

    int size = tmp.size() / 2;
    for (idx = 0; idx < tmp.size(); idx++) {
        int div = yellow / tmp[idx];
        if (brown == (2 * (tmp[idx] + div + 2)))
            break;
    }
    answer.emplace_back(yellow / tmp[idx] + 2);
    answer.emplace_back(tmp[idx]+2);
    
    return answer;
}