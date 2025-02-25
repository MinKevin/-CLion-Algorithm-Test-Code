#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

void input() {
    cin >> N;
    dp = vector(N + 1, -1);
}

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    return dp[pos] = (dpFunction(pos - 1) + dpFunction(pos - 2)) % 15746;
}

void solution() {
    dp[1] = 1;
    dp[2] = 2;
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
