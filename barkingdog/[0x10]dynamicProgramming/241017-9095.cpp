#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> testcases;
vector<int> dp;
vector<int> answers;

void input() {
    cin >> T;
    testcases = vector(T, 0);

    for (int i = 0; i < T; i++) {
        cin >> testcases[i];
    }
}

int dpFunction(int number) {
    if (dp[number] != 0)
        return dp[number];


    dp[number] = dpFunction(number - 1) + dpFunction(number - 2) + dpFunction(number- 3);
    return dp[number];
}

void solution() {
    for (int testcase : testcases) {
        dp = vector(testcase + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        answers.push_back(dpFunction(testcase));
    }
}

void output() {
    for (int answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
