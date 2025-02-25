#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;
int answer;

void input() {
    cin >> n >> k;
    coins = vector<int>(n);
    dp = vector(k + 1, -2);
    answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
}

int dpFunction(int pos) {
    if (dp[pos] != -2)
        return dp[pos];

    int minCount = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (pos - coins[i] >= 0 && dpFunction(pos - coins[i]) >= 0 && minCount > dpFunction(pos - coins[i]) + 1) {
            minCount = dpFunction(pos - coins[i]) + 1;
        }
    }

    if (minCount == INT_MAX)
        return dp[pos] = -1;

    return dp[pos] = minCount;
}

void solution() {
    sort(coins.begin(), coins.end(), less<>());
    dp[0] = 0;
}

void output() {
    cout << dpFunction(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
