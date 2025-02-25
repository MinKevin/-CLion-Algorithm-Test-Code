#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> board;
int answer;
void input() {
    cin >> N >> K;
    board = vector(N + 1, 0);
    answer = 0;
}

void solution() {
    for (int i = 2; i <= N; i++) {
        board[i] = i;
    }

    int counter = 0;
    for (int i = 2; i <= N; i++) {
        if (board[i] == -1)
            continue;
        for (int j = 1; j * i <= N; j++) {
            if (board[i * j] != -1) {
                counter++;
                board[i * j] = -1;

                if (counter == K) {
                    answer = i * j;
                    return;
                }
            }
        }
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
