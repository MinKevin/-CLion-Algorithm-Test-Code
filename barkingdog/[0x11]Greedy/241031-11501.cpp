#include <sstream>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int T;
vector<int> N;
vector<vector<ll> > costs;
vector<vector<ll> > highPoints;
vector<ll> answers;

void input() {
    cin >> T;
    N = vector(T, 0);
    costs = vector(T, vector<ll>());
    highPoints = vector(T, vector<ll>());
    for (int t = 0; t < T; t++) {
        cin >> N[t];

        int inp;
        for (int i = 0; i < N[t]; i++) {
            cin >> inp;
            costs[t].push_back(inp);
        }
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < costs[t].size(); i++) {
            while (!highPoints[t].empty() && highPoints[t].back() < costs[t][i]) {
                highPoints[t].pop_back();
            }
            highPoints[t].push_back(costs[t][i]);
        }
        ll answer = 0;
        ll sum = 0;
        int excur = 0;
        int cur = 0;
        for (int i = 0; i < costs[t].size(); i++) {
            if (costs[t][i] != highPoints[t][cur]) {
                sum += costs[t][i];
            } else {
                answer += highPoints[t][cur++] * (i - excur) - sum;
                sum = 0;
                excur = i + 1;
            }
        }
        answers.push_back(answer);
    }
}

void output() {
    for (ll answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
