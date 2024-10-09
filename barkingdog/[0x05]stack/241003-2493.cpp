#include "../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

ostringstream oss;

int N;
vector<int> inp;
vector<int> answer;
stack<pair<int, int> > s;

void input() {
    cin >> N;

    inp = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    }
}

void solution() {
    answer = vector<int>(N, 0);

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top().first <= inp[i]) {
            s.pop();
        }
        if (s.empty()) {
            answer[i] = 0;
            s.push(make_pair(inp[i], i + 1));
        } else {
            answer[i] = s.top().second;
            s.push(make_pair(inp[i], i + 1));
        }
    }
}

void output() {
    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    streambuf *p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(p_cout_streambuf);
    output();
}
