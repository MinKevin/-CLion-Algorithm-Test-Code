#include "../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostringstream oss;

int N, M;
vector<int> inp;
vector<bool> vis(10, false);
vector<int> answer;

void recursive(int st, int depth) {
    if (depth == M) {
        for (int ans : answer) {
            oss << ans << " ";
        }
        oss << '\n';
        return;
    }

    for (int i = st; i < inp.size(); i++) {
        answer.push_back(inp[i]);
        recursive(i, depth + 1);
        answer.pop_back();
    }
}

void input() {
    inp.clear();
    vis = vector<bool>(10, false);
    answer.clear();
    oss.str("");
    oss.clear();

    cin >> N >> M;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (vis[input] == false) {
            vis[input] = true;
            inp.push_back(input);
        }
    }
}

void solution() {
    sort(inp.begin(), inp.end());
    recursive(0, 0);
}

void output() {
    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    streambuf* p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(p_cout_streambuf);
    output();
}