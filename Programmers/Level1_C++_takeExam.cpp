#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> count;
    vector<int> answer;
    for (int i = 0; i < answers.size(); i++) {
        if (i+1 == (answers[i] % 6))
            count[0] += 1;
     
    }
    return answer;
}