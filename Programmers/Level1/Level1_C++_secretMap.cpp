#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        vector<int> tmp1;
        vector<int> tmp2;
        for (int j = 0; j < n; j++) {
            double tmp3 = pow(2, n - j - 1);
            int tmp = (int)tmp3;

            if (arr1[i] - tmp >= 0) {
                arr1[i] -= tmp;
                tmp1.emplace_back(1);
            }
            else
                tmp1.emplace_back(0);

            tmp3 = pow(2, n - j - 1);
            tmp = (int)tmp3;
            if (arr2[i] - tmp >= 0) {
                arr2[i] -= tmp;
                tmp2.emplace_back(1);
            }
            else
                tmp2.emplace_back(0);
        }
        v1.emplace_back(tmp1);
        v2.emplace_back(tmp2);
        
    }

    for (int i = 0; i < n; i++) {
        string str1;
        for (int j = 0; j < n; j++) {
            if (v1[i][j] + v1[i][j]>0)
                str1.push_back('#');
            else
                str1.push_back(' ');
        }
        answer.emplace_back(str1);
    }

    return answer;
}