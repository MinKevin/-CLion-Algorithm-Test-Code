#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;
int answer = 0;

void input() {
    cin >> N;
    dp = vector(N + 1, -1);
}

int dpFunction(int num) {
    if (dp[num] != -1)
        return dp[num];

    dp[num] = num;
    for (int i = 1; i * i <= num; i++) {
        dp[num] = min(dp[num], dpFunction(num - i * i) + 1);
    }
    return dp[num];
}

int dpFunction2(int n, int i) {
    if (i == 0)
        return n == 0;

    int maxNum = 1;
    while (maxNum * maxNum * i < n) {
        maxNum++;
    }

    for(; maxNum * maxNum <= n; maxNum++) {
        if (dpFunction2(n - maxNum * maxNum, i - 1))
            return 1;
    }
    return 0;
}

void solution() {
    dp[0] = 0;
    answer = dpFunction(N);
}

void output() {
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
