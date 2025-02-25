#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> M, N, x, y;
vector<int> answers;

void input() {
    cin >> T;
    M = vector(T, 0);
    N = vector(T, 0);
    x = vector(T, 0);
    y = vector(T, 0);

    for (int i = 0; i < T; i++) {
        cin >> M[i] >> N[i] >> x[i] >> y[i];
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int getYear(int M, int N, int x, int y) {
    int result = lcm(M, N);
    for (; x <= result; x += M) {
        if ((x - 1) % N + 1 == y)
            return x;
    }

    return -1;
}

void solution() {
    for (int t = 0; t < T; t++) {
        answers.push_back(getYear(M[t], N[t], x[t], y[t]));
    }
}

void output() {
    for (int answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
