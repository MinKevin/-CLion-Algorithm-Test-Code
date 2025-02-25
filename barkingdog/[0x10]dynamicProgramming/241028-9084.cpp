#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> N;
vector<vector<int>> coins;
vector<int> values;
vector<int> answers;
vector<vector<int>> dps;

void input() {
    cin >> T;
    N = vector(T, 0);
    coins = vector<vector<int>>(T);
    values = vector(T, 0);
    dps = vector<vector<int>>(T);
    for (int t = 0; t < T; t++) {
        cin >> N[t];

        int inp;
        for (int i = 0; i < N[t]; i++) {
            cin >> inp;
            coins[t].push_back(inp);
        }
        cin >> values[t];
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        dps[t] = vector(values[t] + 1, 0);
        dps[t][0] = 1;

        for (int i = 0; i < coins[t].size(); i++) {
            for (int j = coins[t][i]; j <= values[t]; j++) {
                dps[t][j] += dps[t][j - coins[t][i]];
            }
        }

        answers.push_back(dps[t][values[t]]);
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
