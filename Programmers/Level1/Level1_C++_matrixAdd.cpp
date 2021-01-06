#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int tmp;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> v;
        for (int j = 0; j < arr1[0].size(); j++) {
            v.emplace_back(move(arr1[i][j] + arr2[i][j]));
        }
        answer.emplace_back(v);
    }


    return answer;
}