#include <sstream>
#include <iostream>
#include <vector>

#define MAX_NUM 1000000

using namespace std;

int N;
vector<pair<int, int> > dp;
int answer;

void input() {
    cin >> N;
    dp = vector<pair<int, int> >(MAX_NUM * 2 + 1, {0, false});
}

int dpFunction(int pos) {
    if (dp[pos].second == true)
        return dp[pos].first;


    if (pos >= MAX_NUM) {
        dp[pos] = {(dpFunction(pos - 1) + dpFunction(pos - 2)) % 1000000000, true};
        return dp[pos].first;
    }
    dp[pos] = {(dpFunction(pos + 2) - dpFunction(pos + 1)) % 1000000000, true};
    return dp[pos].first;
};

void solution() {
    dp[MAX_NUM] = {0, true};
    dp[MAX_NUM + 1] = {1, true};
    answer = dpFunction(N + MAX_NUM);
}

void output() {
    if (answer < 0)
        cout << -1 << '\n';
    else if (answer == 0)
        cout << 0 << '\n';
    else if (answer > 0)
        cout << 1 << '\n';

    cout << abs(answer) << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
