#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > board;
vector<bool> visitedForTopToDownCrossLine;
vector<bool> visitedForDownToTopCrossLine;
vector<bool>::iterator visitedForTopToDownCrossLineIter;
vector<bool>::iterator visitedForDownToTopCrossLineIter;
vector<int> answer;

void input() {
    cin >> N;
    board = vector(N, vector(N, 0));
    visitedForTopToDownCrossLine = vector(2 * N - 1, false);
    visitedForDownToTopCrossLine = vector(2 * N - 1, false);
    visitedForTopToDownCrossLineIter = visitedForTopToDownCrossLine.begin() + N - 1;
    visitedForDownToTopCrossLineIter = visitedForDownToTopCrossLine.begin() + N - 1;
    answer = vector(2, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

int dfs(int loc, int counter) {
    int answerBuf = counter;
    for (int i = loc; i < N * N;) {
        if (board[i / N][i % N] == 1 &&
            visitedForDownToTopCrossLineIter[i / N + i % N] == false &&
            visitedForTopToDownCrossLineIter[i / N - i % N] == false) {
            visitedForDownToTopCrossLineIter[i / N + i % N] = true;
            visitedForTopToDownCrossLineIter[i / N - i % N] = true;
            int result = dfs(i, counter + 1);
            if (result > answerBuf)
                answerBuf = result;
            visitedForDownToTopCrossLineIter[i / N + i % N] = false;
            visitedForTopToDownCrossLineIter[i / N - i % N] = false;
        }
        if (N % 2 == 0 && i / N < (i + 2) / N) {
            if (i % 2 == 0)
                i += 3;
            else
                i += 1;
        } else
            i += 2;
    }
    return answerBuf;
}

void solution() {
    answer[0] = dfs(0, 0);
    answer[1] = dfs(1, 0);
}

void output() {
    cout << answer[0] + answer[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
