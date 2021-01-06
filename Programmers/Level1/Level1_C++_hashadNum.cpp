#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int y = x;
    int check = 0;

    while (true) {
        check = check + (y % 10);
        y /= 10;
        if (y == 0)
            break;
    }

    if (x % check == 0)
        answer = true;

    return answer;
}