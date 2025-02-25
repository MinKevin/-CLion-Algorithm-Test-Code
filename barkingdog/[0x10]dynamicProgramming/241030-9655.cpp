
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;

void input() {
    cin >> N;
    dp = vector(N + 1, 0);
}

void solution() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
    }
}

void output() {
    if (dp[N] % 2 == 1)
        cout << "SK";
    else
        cout << "CY";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
