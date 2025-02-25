#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct counter {
    int num2;
    int num5;
};

int N;
vector<counter> dp;
int answer;

void input() {
    cin >> N;
    dp = vector<counter>(N + 1, {-1, -1});
}

counter dpFunction(int pos) {
    if (dp[pos].num2 != -1) {
        return dp[pos];
    }

    dp[pos].num2 = dpFunction(pos - 1).num2;
    if (pos % 2 == 0)
        dp[pos].num2 += dpFunction(pos / 2).num2 - dpFunction(pos / 2 - 1).num2 + 1;

    dp[pos].num5 = dpFunction(pos - 1).num5;
    if (pos % 5 == 0)
        dp[pos].num5 += dpFunction(pos / 5).num5 - dpFunction(pos / 5 - 1).num5 + 1;

    return dp[pos];
}

void solution() {
    dp[0] = {0, 0};
    dp[1] = {0, 0};
    answer = min(dpFunction(N).num2, dpFunction(N).num5);
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
