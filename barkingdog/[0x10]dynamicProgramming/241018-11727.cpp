#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;
int answer;

void input() {
    cin >> N;
    dp = vector(N + 1, -1);
}

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    return dp[pos] = (dpFunction(pos - 1) + 2 * dpFunction(pos - 2)) % 10007;
}

void solution() {
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5; // dp[n - 2] * 2 + dp[n - 1]
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
