#include <sstream>
#include <iostream>
#include <math.h>
using namespace std;

ostringstream oss;

int N;

void input() {
    cin >> N;
}

void recursive(int from, int by, int to, int n) {
    if (n == 1) {
        oss << from << ' ' << to << '\n';
        return;
    }
    recursive(from, to, by, n - 1);
    oss << from << ' ' << to << '\n';
    recursive(by, from, to, n - 1);
}

void solution() {
    oss << static_cast<int>(pow(2, N) - 1) << '\n';
    recursive(1, 2, 3, N);
}

void output() {
    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    streambuf *pCoutStreamBuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(pCoutStreamBuf);
    output();
}
