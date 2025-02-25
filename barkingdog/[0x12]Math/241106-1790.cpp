#include <sstream>
#include <iostream>

using namespace std;

int n, k;
int answer;

void input() {
    cin >> n >> k;
}

void solution() {
    int exp = 1;
    int len = 1;
    while (k > 9LL * exp * len) {
        k -= 9LL * exp * len;
        exp *= 10;
        len++;
    }

    int quotient = (k - 1) / len;
    int remainder = (k - 1) % len + 1;
    int target = exp + quotient;
    if (target > n) {
        answer = -1;
        return;
    }

    for (int i = 0; i < len - remainder; i++) {
        target /= 10;
    }
    answer = target % 10;
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
