#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int check = 0;

    for (int i = 0; i < s.length(); i++) {
        char tmp = s[i];

        if (tmp == '(')
            check++;
        else if (tmp == ')')
            check--;

        if (check < 0)
            return false;
    }
    if (check != 0)
        return false;

    return answer;
}