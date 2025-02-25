#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> isColumnUsed;
vector<bool> isTopDownDiagonalUsed;
vector<bool> isDownTopDiagonalUsed;
vector<bool>::iterator isTopDownDiagonalUsedCursor;
vector<bool>::iterator isDownTopDiagonalUsedCursor;
int answer;

void input() {
    cin >> N;
    isColumnUsed = vector(N, false);
    isTopDownDiagonalUsed = vector(2 * N - 1, false);
    isDownTopDiagonalUsed = vector(2 * N - 1, false);
    isTopDownDiagonalUsedCursor = isTopDownDiagonalUsed.begin() + N;
    isDownTopDiagonalUsedCursor = isDownTopDiagonalUsed.begin() + N;
    answer = 0;
}

void dfs(int depth) {
    if (depth == N) {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isColumnUsed[i] && !*(isTopDownDiagonalUsedCursor + (depth - i)) && !*(isDownTopDiagonalUsedCursor + (depth + i))) {
            isColumnUsed[i] = true;
            isTopDownDiagonalUsedCursor[depth - i] = true;
            isDownTopDiagonalUsedCursor[depth + i] = true;
            dfs(depth + 1);
            isColumnUsed[i] = false;
            isTopDownDiagonalUsedCursor[depth - i] = false;
            isDownTopDiagonalUsedCursor[depth + i] = false;
        }
    }
}

void solution() {
    dfs(0);
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
