#include <sstream>
#include <iostream>

using namespace std;

int X;
int x, y;
void input() {
    cin >> X;
}

void solution() {
    int n = 1;
    for (; n < X; n++) {
        X -= n;
    }

    if (n % 2 == 1) {
        x = n - X + 1;
        y = X;
    } else {
        x = X;
        y = n - X + 1;
    }
}

void output() {
    cout << x << "/" << y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
