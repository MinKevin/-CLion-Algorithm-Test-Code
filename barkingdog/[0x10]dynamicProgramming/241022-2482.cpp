#include <sstream>
#include <iostream>
#include <vector>

#define moder 1000000003

using namespace std;
int N, K;
vector<vector<int> > dpCounter;

void input() {
    cin >> N >> K;
    dpCounter = vector(N + 1, vector(K + 1, 0));
}

void solution() {
    for (int i = 1; i <= N; i++) {
        dpCounter[i][1] = i;
        dpCounter[i][0] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dpCounter[i][j] = (dpCounter[i - 2][j - 1] + dpCounter[i - 1][j]) % moder;
        }
    }
}

void output() {
    cout << (dpCounter[N - 1][K] + dpCounter[N - 3][K - 1]) % moder;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
