#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
queue<int> q;
vector<int> vis;
int answer;

void input() {
    cin >> N >> M;
    vis = vector(N + 1, -1);
    answer = 0;

    int inp;
    for (int i = 0; i < M; i++) {
        cin >> inp;
        q.push(inp);
        vis[inp] = 0;
    }
}

void solution() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= N; i <<= 1) {
            int nx = cur ^ i;

            if (nx <= N && vis[nx] == -1) {
                vis[nx] = vis[cur] + 1;
                answer = vis[nx];
                q.push(nx);
            }
        }
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
