#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> combination;
string answer;

void input() {
    cin >> N >> M >> K;
    combination = vector(N + M, vector(N + M, 0));
}

void solution() {
    for (int i = 0; i < N + M; i++) {
        combination[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
            if (combination[i][j] > 1000000000)
                combination[i][j] = 1000000000;
        }
    }

    while (N && M) {
        if (combination[N - 1 + M][M] < K) {
            K -= combination[N - 1 + M][M];
            M--;
            answer.push_back('z');
        } else {
            N--;
            answer.push_back('a');
        }
    }

    while(N--)
        answer.push_back('a');
    while(M--)
        answer.push_back('z');
}

void output() {
    if (K > 1)
        cout << -1;
    else
        cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
