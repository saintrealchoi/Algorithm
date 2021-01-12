#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;

    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> tmp;
    vector<int> list;
    for (int i = 0; i < numbers.length(); i++) {
        tmp.emplace_back(numbers[i]-'0');
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 1; i < tmp.size() + 1; i++) {
        do {
            int tmp2 = 0;
            for (int j = 0; j < i; j++ ) {
                tmp2 += (tmp[j] * (int)pow(10, j));
            }
            list.emplace_back(tmp2);
        } while (next_permutation(tmp.begin(),tmp.end()));
    }

    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());

    for (int i = 0; i < list.size(); i++) {
        
        if (isPrime(list[i]))
            answer++;
    }


    return answer;
}