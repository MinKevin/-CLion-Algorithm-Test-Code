#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct timeAndPayS {
    int time;
    int pay;
};
int N;
vector<timeAndPayS> timeAndPay;
vector<int> dp;

void input() {
    cin >> N;
    timeAndPay = vector<timeAndPayS>(N);
    dp = vector(N + 1, 0);
    int time, pay;
    for (int i = 0; i < N; i++) {
        cin >> time >> pay;
        timeAndPay[i] = {time, pay};
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        if (i > 0 && dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];

        int endTime = i + timeAndPay[i].time;
        if (endTime <= N &&
            dp[i] + timeAndPay[i].pay > dp[endTime]) {
            dp[endTime] = dp[i] + timeAndPay[i].pay;
        }
        else if (endTime > N &&
            dp[i] > dp[N]) {
            dp[N] = dp[i];
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
