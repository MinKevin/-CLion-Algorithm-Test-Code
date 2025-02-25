#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> dp;
int answer;

void input() {
    cin >> N;
    dp = vector(N + 1, -1);
}

void solution() {
    queue<int> q;
    q.push(N);
    dp[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 1) {
            answer = dp[cur];
            return;
        }

        if (cur % 3 == 0 && dp[cur / 3] == -1) {
            dp[cur / 3] = dp[cur] + 1;
            q.push(cur / 3);
        }

        if (cur % 2 == 0 && dp[cur / 2] == -1) {
            dp[cur / 2] = dp[cur] + 1;
            q.push(cur / 2);
        }

        if (dp[cur - 1] == -1) {
            dp[cur - 1] = dp[cur] + 1;
            q.push(cur - 1);
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
