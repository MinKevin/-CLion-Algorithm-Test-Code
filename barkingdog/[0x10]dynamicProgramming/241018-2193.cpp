#include <sstream>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
vector<ll> dp;
ll answer;

void input() {
    cin >> N;
    dp = vector<ll>(N + 1, -1);
}

ll dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    return dp[pos] = dpFunction(pos - 1) + dpFunction(pos - 2);
}

void solution() {
    dp[1] = 1;
    dp[2] = 1;

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
