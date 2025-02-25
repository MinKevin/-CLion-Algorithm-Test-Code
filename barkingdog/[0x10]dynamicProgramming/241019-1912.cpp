#include <sstream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> nums;
vector<int> dp;
int result;

void input() {
    cin >> N;
    dp = vector(N, -1);
    nums.clear();
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }
}

void solution() {
    dp[0] = nums[0];
    result = nums[0];
    int min = nums[0];
    for (int i = 1; i < N; i++) {
        dp[i] = nums[i] + dp[i - 1];

        int resultBuf = min < 0 ? dp[i] - min : dp[i];
        if (resultBuf > result) {
            result = resultBuf;
        }

        if (dp[i] < min)
            min = dp[i];

    }
}

void output() {
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
