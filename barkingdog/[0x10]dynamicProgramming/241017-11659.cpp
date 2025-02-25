#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> nums;
vector<int> dp;
vector<pair<int, int>> scopes;
vector<int> answer;
void input() {
    cin >> N >> M;
    nums = vector(N + 1, 0);
    dp = vector(N + 1, -1);
    scopes = vector<pair<int, int>>(M);
    answer.clear();

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        scopes[i] = {a, b};
    }
}

int dpFunction(int target) {
    if (dp[target] != -1)
        return dp[target];

    return dp[target] = nums[target] + dpFunction(target - 1);
}

void solution() {
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 0; i < scopes.size(); i++) {
        answer.push_back(dpFunction(scopes[i].second) - dpFunction(scopes[i].first - 1));
    }
}

void output() {
    for (int ans : answer)
        cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}