#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    vector <int> power;
    double root;
    long long check = 0;
    double check2;
    long long answer = 0;
    
    root = sqrt(n);
    check = (long long)root;
    check2 = (double)check;
    if (check == root) {
        return pow(root + 1, 2);
    }

    return -1;
}