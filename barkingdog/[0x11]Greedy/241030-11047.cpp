#include <sstream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K;
vector<int> coins;
int answer;

void input() {
    cin >> N >> K;
    coins = vector(N, 0);

    for (int i = 0; i < N; i++)
        cin >> coins[i];
}

void solution() {
    int remainder = K;
    for (int i = coins.size() - 1; i >= 0; i--) {
        answer += remainder / coins[i];
        remainder = remainder % coins[i];
    }
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
