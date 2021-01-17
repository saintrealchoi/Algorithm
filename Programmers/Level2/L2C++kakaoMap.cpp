#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    int size = cities.size();

    if (cacheSize == 0) {
        answer = size * 5;
        return answer;
    }

    for (int i = 0; i < size; i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        vector<string> ::iterator it = find(cache.begin(), cache.end(), cities[i]);

        if (it != cache.end()) {
            string city = *it;
            cache.erase(it);
            cache.emplace_back(city);
            answer++;
        }
        else {
            if (cache.size() < cacheSize) {
                cache.emplace_back(cities[i]);
            }
            else {
                cache.erase(cache.begin());
                cache.emplace_back(cities[i]);
            }
            answer += 5;
        }
    }
    return answer;
}
