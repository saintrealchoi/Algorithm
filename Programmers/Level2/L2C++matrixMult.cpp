#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> v;
        for (int j = 0; j < arr2[0].size(); j++) {
            int tmp = 0;
            for (int k = 0; k < arr2.size(); k++) {
                int tmp1 = move(arr1[i][k]);
                int tmp2 = move(arr2[k][j]);
                tmp += (tmp1 * tmp2);
            }
            v.emplace_back(tmp);
        }
        answer.emplace_back(v);
    }
    return answer;
}