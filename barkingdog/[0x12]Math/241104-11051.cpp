#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> dp;

void input() {
    cin >> N >> K;
    dp = vector(N + 1, vector(K + 1, -1));
}

int dpFunction(int n, int k) {
    if (dp[n][k] != -1)
        return dp[n][k];

    if (k == 0 || n == k)
        return dp[n][k] = 1;

    return dp[n][k] = (dpFunction(n - 1, k - 1) + dpFunction(n - 1, k)) % 10007;
}

void solution() {

}

void output() {
    cout << dpFunction(N, K);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
