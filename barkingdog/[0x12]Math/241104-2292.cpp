#include <sstream>
#include <iostream>

using namespace std;

int N;
int answer;

void input() {
    cin >> N;
}

void solution() {
    if (N == 1) {
        answer = 2;
        return;
    }

    int buffer = 1;
    for (answer = 2; buffer < N; answer++) {
        buffer += 6 * (answer - 1);
    }
}

void output() {
    cout << answer - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
