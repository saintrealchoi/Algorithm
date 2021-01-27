#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = triangle.size()-2; i > 0 ; --i) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}