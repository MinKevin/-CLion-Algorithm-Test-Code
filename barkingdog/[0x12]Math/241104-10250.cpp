#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> H, W, N;
vector<int> answers;

void input() {
    cin >> T;

    int h, w, n;
    for (int t = 0; t < T; t++) {
        cin >> h >> w >> n;
        H.push_back(h);
        W.push_back(w);
        N.push_back(n);
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        answers.push_back(((N[t] - 1) % H[t] + 1) * 100
            +  N[t] / H[t] + (N[t] % H[t] == 0 ? 0 : 1));
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
