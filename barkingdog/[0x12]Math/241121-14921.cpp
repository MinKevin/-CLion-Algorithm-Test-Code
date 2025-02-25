#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> As;
int answer = 200'000'001;

void input() {
    cin >> N;
    As = vector(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }
}

void solution() {
    int st = 0;
    int en = N - 1;
    while (st < en) {
        if (abs(As[st] + As[en]) < abs(answer)) {
            answer = As[st] + As[en];
        }

        if (As[st] + As[en] < 0)
            st++;
        else if (As[st] + As[en] == 0)
            break;
        else
            en--;
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
