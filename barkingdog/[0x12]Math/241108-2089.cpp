#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> answer;

void input() {
    cin >> N;
}

void solution() {
    if (N == 0)
        answer.push_back(0);

    while(N) {
        if (N % -2) {
            answer.push_back(1);
            if (N % -2 < 0)
                N  = N / -2 + 1;
            else
                N /= -2;
        } else {
            answer.push_back(0);
            N /= -2;
        }
    }
}

void output() {
    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
