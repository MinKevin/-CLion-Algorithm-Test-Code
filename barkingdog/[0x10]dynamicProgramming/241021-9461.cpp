#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> question;
vector<long long> dp;
void input() {
    cin >> T;

    question = vector(T, -1);
    dp = vector(100, static_cast<long long>(-1));
    for (int i = 0; i < T; i++) {
        cin >> question[i];
    }
}

void solution() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;

    for (int i = 5; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
}

void output() {
    for (int i = 0; i < T; i++) {
        cout << dp[question[i] - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
