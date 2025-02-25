#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> fixedSeat;
vector<int> dp;
int answer;

void input() {
    cin >> N >> M;
    dp = vector(N + 1, -1);
    answer = 1;

    int inp;
    for (int i = 0; i < M; i++) {
        cin >> inp;
        fixedSeat.push_back(inp);
    }
    fixedSeat.push_back(N + 1);
}

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    return dp[pos] = dpFunction(pos - 1) + dpFunction(pos - 2);
}

void solution() {
    dp[0] = 1;
    dp[1] = 1;
    int st = 0;
    for (int i = 0; i < fixedSeat.size(); i++) {
        answer *= dpFunction(fixedSeat[i] - st - 1);
        st = fixedSeat[i];
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
