#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    vector<int> v;
    int answer = 0;
    int index = 0;

    //ASCII '1' = 49, 'S' = 83 'D'=68 'T'=84 '*'=42 '#'=35
    for (int i = 0; i < dartResult.size(); i++) {
        int c = (int)dartResult[i];
        int c2 = (int)dartResult[i+1];

        if (47 < c && c < 58  && c2 != 48) {
            v.emplace_back(c-48);
            index++;
            continue;
        }
        if (c == 49 && c2 == 48) {
            v.emplace_back(c - 39);
            index++;
            i++;
            continue;
        }
        if (c == 68) {
            v[index - 1] = (int)pow(v[index - 1], 2);
            continue;
        }
        if (c == 84) {
            v[index -1 ] = (int)pow(v[index - 1], 3);
            continue;
        }
        if (c == 42) {
            int tmp1 = move(v[index - 1] * 2);
            int tmp2 = move(v[index - 2] * 2);
            v[index - 1] = tmp1;
            v[index - 2] = tmp2;
            continue;
        }
        if (c == 35) {
            v[index-1] *= -1;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; 
        answer += v[i];
    }
    return answer;
}