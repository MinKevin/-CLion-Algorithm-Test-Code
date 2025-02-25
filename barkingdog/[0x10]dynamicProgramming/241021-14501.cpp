#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> timeAndPay;
vector<int> dp;
void input() {
    cin >> N;
    timeAndPay = vector<pair<int, int>>(N + 1);
    dp = vector(N + 1, 0);

    int t, p;
    for (int i = 0; i < N; i++) {
        cin >> t >> p;
        timeAndPay[i] = {t, p};
    }
}

void solution() {
    for (int i = 0; i <= N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (timeAndPay[j].first <= i - j && dp[j] + timeAndPay[j].second > dp[i])
                dp[i] = dp[j] + timeAndPay[j].second;
        }
    }
}

void output() {
    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
