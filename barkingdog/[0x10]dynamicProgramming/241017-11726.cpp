#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;
int answer;

void input() {
    cin >> N;
    dp = vector(N + 1, -1);
    answer = 0;
}

int dpFunction(int loc) {
    if (dp[loc] != -1)
        return dp[loc];

    dp[loc] = (dpFunction(loc - 1) + dpFunction(loc - 2)) % 10007;
    return dp[loc];
}

void solution() {
    dp[1] = 1;
    dp[2] = 2;


    answer = dpFunction(N);
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
