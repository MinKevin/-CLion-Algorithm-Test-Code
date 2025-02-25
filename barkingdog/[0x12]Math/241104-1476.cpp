#include <sstream>
#include <iostream>

using namespace std;

int E, S, M;
int answer;

void input() {
    cin >> E >> S >> M;
}

void solution() {
    while (true) {
        if ((E - 1) % 28 + 1 == S && (E - 1) % 19 + 1 == M) {
            answer = E;
            break;
        }
        E += 15;
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
