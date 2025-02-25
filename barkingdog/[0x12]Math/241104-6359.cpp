#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> N;
vector<bool> doors;
vector<int> dp;
vector<int> answers;

void input() {
    cin >> T;
    N = vector(T, 0);
    doors = vector(101, false);
    dp = vector(101, 0);
    for (int t = 0; t < T; t++) {
        cin >> N[t];
    }
}

void solution() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; i * j <= 100; j++) {
            doors[i * j] = !doors[i * j];
        }
    }

    int openedDoorCount = 0;
    for (int i = 1; i <= 100; i++) {
        if (doors[i]) {
            openedDoorCount++;
        }
        dp[i] = openedDoorCount;
    }

    for (int t = 0; t < T; t++) {
        answers.push_back(dp[N[t]]);
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
