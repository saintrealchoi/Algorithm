bool prime[1000000]{ false };

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i - 1])continue;
        answer++;
        for (int j = i + i; j <= n; j += i)prime[j - 1] = true;
    }
    return answer;
}