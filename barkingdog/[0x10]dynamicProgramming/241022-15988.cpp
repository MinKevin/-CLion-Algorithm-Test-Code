#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<long long> question;
vector<long long> dp;

void input() {
    cin >> T;

    dp = vector<long long>(1000001, -1);

    int inp;
    for (int i = 0; i < T; i++) {
        cin >> inp;
        question.push_back(inp);
    }
}

long long dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    return dp[pos] = (dpFunction(pos - 1) + dpFunction(pos - 2) + dpFunction(pos - 3)) % 1000000009;
}

void solution() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
}

void output() {
    for (int i = 0; i < T; i++)
        cout << dpFunction(question[i]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
