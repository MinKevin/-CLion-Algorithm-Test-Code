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
        ll answer = 0;
        ll maxCosts = costs[t][costs[t].size() - 1];
        for (int i = costs[t].size() - 1; i >= 0; i--) {
            if (costs[t][i] > maxCosts) {
                maxCosts = costs[t][i];
            } else {
                answer += maxCosts - costs[t][i];
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
