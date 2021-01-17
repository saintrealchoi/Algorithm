#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hash;

    for (auto cloth : clothes) hash[cloth[1]] += 1;

    for (auto it = hash.begin(); it != hash.end(); it++) answer *= (it->second + 1);

    return answer - 1;
}