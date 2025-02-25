#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;
void input() {
    cin >> n >> k;
    dp = vector(k + 1, 0);

    int inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        coins.push_back(inp);
    }
}

/* pos = 3;
 * i = 0; dp[3] = 0; dpFunction(3 - 1) -> dp[2] => 1 1 1 / 2 1 => 2가지
 * i = 1;            dpFunction(3 - 2) -> dp[1] => 1 2 => 1가지
 */

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    dp[pos] = 0;
    for (int i = 0; i < k; i++) {
        dp[pos] += dpFunction(pos - coins[i]);
    }
    return dp[pos];
}

void solution() {
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
}

void output() {
    cout << dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
