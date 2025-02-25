#include <sstream>
#include <iostream>

using namespace std;

int A, B, V;
int answer;

void input() {
    cin >> A >> B >> V;
}

void solution() {
    int dayMove = A - B;
    int newLength = V - B;

    answer = newLength / dayMove
    + (newLength % dayMove == 0 ? 0 : 1);
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
