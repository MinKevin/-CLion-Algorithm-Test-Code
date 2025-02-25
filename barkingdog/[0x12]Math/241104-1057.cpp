#include <sstream>
#include <iostream>

using namespace std;

int N, x, y;
int answer = 1;

void input() {
    cin >> N >> x >> y;
}

void solution() {
    x -= 1;
    y -= 1;
    while (x / 2 != y / 2) {
        x /= 2;
        y /= 2;
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
