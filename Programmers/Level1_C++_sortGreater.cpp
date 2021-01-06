#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    vector <int> v;
    long long answer = n;
    int count = 0;
    while ( answer > 0 ){
        answer /= 10;
        count++;
    }
    answer = n;
    for (int i = 0; i < count; i++) {
        v.emplace_back(answer % 10);
        answer /= 10;
    }
    sort(v.begin(), v.end(),greater<int>());
    int size = v.size();
    for (int i = 0; i < size; i++) {
        answer = answer + v.back() * pow(10,i);
        v.pop_back();
    }
    return answer;
}