#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

string inp;
vector<int> dp;
int answer;
void input() {
    cin >> inp;
    inp = " " + inp;
    dp = vector(inp.size(), -1);
}

int dpFunction(int pos) {
    if (dp[pos] != -1)
        return dp[pos];

    dp[pos] = 0;
    if (inp[pos] != '0')
        dp[pos] += dpFunction(pos - 1) % 1000000;

    string num = inp.substr(pos - 1, 2);
    if ("10" <= num && num <= "26")
        dp[pos] += dpFunction(pos - 2) % 1000000;
    return dp[pos] %= 1000000;
}

void solution() {
    if (inp[1] == '0') {
        answer = 0;
        return;
    }

    dp[0] = 1;
    dp[1] = 1;
    answer = dpFunction(inp.size() - 1);
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
