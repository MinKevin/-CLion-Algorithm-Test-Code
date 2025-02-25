#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
vector<pair<int, int>> scopes;
vector<vector<int>> dp;
vector<int> answers;

void input() {
    cin >> N;
    numbers = vector(N, 0);
    dp = vector(N, vector(N, -1));
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cin >> M;
    int st, en;
    for (int i = 0; i < M; i++) {
        cin >> st >> en;
        scopes.push_back({st - 1, en - 1});
    }
}

int dpFunction(int from, int to) {
    if (dp[from][to] != -1)
        return dp[from][to];

    if (numbers[from] == numbers[to]) {
        if (from == to || to - from == 1 || dpFunction(from + 1, to - 1) == 1) {
            return dp[from][to] = 1;
        }
    }
    return 0;
}

void solution() {
    for (int i = 0; i < scopes.size(); i++) {
        answers.push_back(dpFunction(scopes[i].first, scopes[i].second));
    }
}

void output() {
    for (int answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
