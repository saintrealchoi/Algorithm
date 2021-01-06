#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    long c;

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long solution(int w, int h) {
    long long W = w;
    long long H = h;

    return (W * H) - ((W + H) - gcd(W, H));
}