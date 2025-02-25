#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> P;
vector<int> dp;

void input() {
    cin >> N;
    P = vector(N + 1, 0);
    dp = vector(N + 1, -1);

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
}

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    int maximum = 0;
    for (int i = 1; i <= pos; i++) {
        maximum = max(max(dpFunction(pos - i) + P[i], P[i]), maximum);
    }
    return dp[pos] = maximum;
}

void solution() {
    dp[0] = 0;
}

void output() {
    cout << dpFunction(N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
