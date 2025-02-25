#include <sstream>
#include <iostream>
#include <vector>
#define MAX_NUM 10000001
using namespace std;

int N;
vector<bool> board(MAX_NUM, true);
vector<int> answers;

void input() {
    cin >> N;
    answers.clear();
}

void solution() {
    board[1] = false;
    for (int i = 2; i < MAX_NUM; i++) {
        if (board[i]) {
            for (int j = 2; j * i < MAX_NUM; j++) {
                board[i * j] = false;
            }

            while(N % i == 0) {
                answers.push_back(i);
                N /= i;
            }
        }
    }
}

void output() {
    for (int answer : answers) {
        cout << answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
