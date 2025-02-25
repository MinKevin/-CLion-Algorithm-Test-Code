#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

int N, r, c;
int answer;

void input() {
    cin >> N >> r >> c;
    answer = 0;
}

void recursive(int n, int r, int c) {
    if (n == 0)
        return;

    int square = pow(2, 2 * n - 2);
    int edge = pow(2, n);
    if (0 <= r && r < edge / 2 && 0 <= c && c < edge / 2) {
        recursive(n - 1, r, c);
    } else if (0 <= r && r < edge / 2 && edge / 2 <= c && c < edge) {
        answer += square;
        recursive(n - 1, r, c - edge / 2);
    } else if (edge / 2 <= r && r < edge && 0 <= c && c < edge / 2) {
        answer += 2 * square;
        recursive(n - 1, r - edge / 2, c);
    } else if (edge / 2 <= r && r < edge && edge / 2 <= c && c < edge) {
        answer += 3 * square;
        recursive(n - 1, r - edge / 2, c - edge / 2);
    }
}

void solution() {
    recursive(N, r, c);
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
