#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

string str1;
string str2;
vector<vector<int>> dp;
int answer;

void input() {
    cin >> str1 >> str2;

    dp = vector(str1.length() + 1, vector(str2.length() + 1, -1));
}

int dpFunction(int str1Pos, int str2Pos) {
    if (dp[str1Pos][str2Pos] != -1)
        return dp[str1Pos][str2Pos];

    if (str1[str1Pos - 1] != str2[str2Pos - 1])
        return dp[str1Pos][str2Pos] = max(dpFunction(str1Pos - 1, str2Pos), dpFunction(str1Pos, str2Pos - 1));

    return dp[str1Pos][str2Pos] = dpFunction(str1Pos - 1, str2Pos - 1) + 1;
}

void solution() {
    for (int i = 0; i < str1.length() + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < str2.length() + 1; i++)
        dp[0][i] = 0;

    answer = dpFunction(str1.length(), str2.length());
}

void output() {
    cout << answer << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
