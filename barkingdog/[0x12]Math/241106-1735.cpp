#include <sstream>
#include <iostream>

using namespace std;

int P1, P2, C1, C2;
int answerChild, answerParent;

void input() {
    cin >> C1 >> P1 >> C2 >> P2;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solution() {
    int child = C1 * P2 + C2 * P1;
    int parent = P1 * P2;
    int gcdResult = gcd(parent, child);

    answerChild = child / gcdResult;
    answerParent = parent / gcdResult;
}

void output() {
    cout << answerChild << " " << answerParent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
