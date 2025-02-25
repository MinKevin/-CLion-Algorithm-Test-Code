#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> orders;
vector<int> dp;
int answer;

void input() {
    cin >> N;
    orders = vector(N, 0);
    dp = vector(N + 1, -1);
    answer = 1000000;

    for (int i = 0; i < N; i++) {
        cin >> orders[i];
    }
}

void solution() {
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i] != 1 && dp[orders[i] - 1] != -1) {
            dp[orders[i]] = dp[orders[i] - 1] + 1;
        } else {
            dp[orders[i]] = 1;
        }

        if (N - dp[orders[i]] < answer) {
            answer = N - dp[orders[i]];
        }
    }
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
