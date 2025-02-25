#include <sstream>
#include <iostream>

using namespace std;

int N, K;
int answer;

void input() {
    cin >> N >> K;
    answer = 1;
}

void solution() {
    for (int i = 0; i < K; i++) {
        answer *= N - i;
    }
    for (int i = K; i >= 1; i--) {
        answer /= i;
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
