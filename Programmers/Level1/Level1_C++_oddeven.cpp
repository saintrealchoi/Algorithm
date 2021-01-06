#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if (num % 2 == 0) answer.append("Even");
    else answer.append("Odd");
    return answer;
}