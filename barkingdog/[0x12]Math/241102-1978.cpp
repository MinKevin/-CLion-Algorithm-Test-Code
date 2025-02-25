#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
int answer;

void input() {
    cin >> N;
    numbers = vector(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
}

void solution() {
    vector<bool> board(1001, true);

    board[1] = false;
    for (int i = 2; i <= 1000; i++) {
        if (board[i]) {
            for (int j = 2; j * i <= 1000; j++) {
                board[i * j] = false;
            }
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (board[numbers[i]])
            answer++;
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
