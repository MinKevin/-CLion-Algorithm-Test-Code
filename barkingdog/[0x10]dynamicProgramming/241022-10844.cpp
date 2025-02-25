#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
long long answer;
vector<vector<long long> > endNum;
vector<long long> dp;

void input() {
    cin >> N;

    endNum = vector(N + 1, vector<long long>(10, 0));
    dp = vector<long long>(N + 1, -1);
}

void solution() {
    for (int i = 1; i <= 9; i++)
        endNum[1][i] = 1;
    dp[1] = 9;

    for (int i = 2; i <= N; i++) {
        long long sum = 0;

        endNum[i][0] = endNum[i - 1][1];
        sum += endNum[i][0];

        for (int j = 1; j < 9; j++) {
            endNum[i][j] = (endNum[i - 1][j - 1] + endNum[i - 1][j + 1]) % 1000000000;
            sum += endNum[i][j];
        }
        endNum[i][9] = endNum[i - 1][8];
        sum += endNum[i][9];

        dp[i] = sum % 1000000000;
    }
}

void output() {
    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
