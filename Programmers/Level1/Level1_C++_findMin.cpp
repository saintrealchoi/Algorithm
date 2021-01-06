#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int find = 99999999;
    int index = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (find > arr[i]) {
            find = arr[i];
            index = i;
        }
    }
    arr.erase(arr.begin() + index);
    if (arr.empty()) arr.emplace_back(-1);
    return arr;
}