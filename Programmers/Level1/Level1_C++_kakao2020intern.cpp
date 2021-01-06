#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    int last = 0;
    int check = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        int a = 0;
        int b = 0;
        check = move(numbers[i]);
        cout << check;
        if (check % 3 == 1) {
            answer.push_back('L');
            left = check;
            continue;
        }
        else if(check % 3 == 0 && check != 0){
            answer.push_back('R');
            right = check;
            continue;
        }
        if (right % 3 == 0) {
            right -= 2;
        }

        if (check == 0) {
            check = 11;
        }

        a = abs(check - left);
        b = abs(check - right);
        
        if (a % 3 == 0) a /= 3;
        if (a > 1 && (a % 3 == 1)) a = (a - 1) / 3 + 1;
        if (a > 1 && (a % 3 == 2)) a = (a + 1) / 3 + 1;
        if (b % 3 == 0) b /= 3;
        if (b > 1 && (b % 3 == 1)) b = (b - 1) / 3 + 1;
        if (b > 1 && (b % 3 == 2)) b = (b + 1) / 3 + 1;
        if (a > b) {
            answer.push_back('R');
            right = check;
        }
        else if (a < b) {
            answer.push_back('L');
            left = move(check);
        }
        else {
            if (hand == "left") {
                answer.push_back('L');
                left = move(check);
            }

            else {
                answer.push_back('R');
                right = move(check);
            }
        }
    }
        return answer;
}