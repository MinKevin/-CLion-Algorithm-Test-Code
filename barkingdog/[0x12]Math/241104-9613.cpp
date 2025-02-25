#include <sstream>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int T;
vector<vector<int>> numbers;
vector<ll> answers;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void input() {
    cin >> T;
    numbers = vector<vector<int>>(T);
    int n;
    for (int t = 0; t < T; t++) {
        cin >> n;
        numbers[t] = vector(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> numbers[t][i];
        }
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        answers.push_back(0);
        for (int i = 0; i < numbers[t].size(); i++) {
            for (int j = i + 1; j < numbers[t].size(); j++) {
                answers[t] += gcd(numbers[t][i], numbers[t][j]);
            }
        }
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
