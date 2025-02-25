#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> x, y;
vector<int> answers;

void input() {
    cin >> T;

    int X, Y;
    for (int t = 0; t < T; t++) {
        cin >> X >> Y;
        x.push_back(X);
        y.push_back(Y);
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        int answer = 0;
        int exMove = 0;
        int st = x[t];
        int en = y[t];
        while (st < en) {
            st += exMove + 1;
            en -= exMove + 1;
            exMove++;
            answer += 2;
        }
        if (st - en >= exMove) {
            answer--;
        }

        answers.push_back(answer);
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
