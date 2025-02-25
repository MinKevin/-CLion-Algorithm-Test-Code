#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp(5001, -1);
int answer;

void input() {
    cin >> N;
}

int dpFunction(int weight) {
    if (weight <= 0)
        return 0;

    if (dp[weight] != -1)
        return dp[weight];

    if (dpFunction(weight - 5) != 0) {
        return dp[weight] = dpFunction(weight - 5) + 1;
    }
    if (dpFunction(weight - 3) != 0) {
        return dp[weight] = dpFunction(weight - 3) + 1;
    }
    return dp[weight] = 0;
}

void solution() {
    dp[3] = 1;
    dp[5] = 1;

    answer = dpFunction(N);
}

void output() {
    if (answer == 0)
        cout << -1;
    else
        cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
