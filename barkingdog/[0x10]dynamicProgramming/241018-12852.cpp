#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct visitedStruct {
    bool visited;
    int from;
};

int N;
vector<visitedStruct> visited;
stack<int> answer;

void input() {
    cin >> N;
    visited = vector<visitedStruct>(N + 1, {false, 0});
}

void bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = {true, 0};

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 1) {
            return;
        }

        if (cur % 3 == 0 && !visited[cur/ 3].visited) {
            q.push(cur / 3);
            visited[cur / 3] = {true, cur};
        }
        if (cur % 2 == 0 && !visited[cur/ 2].visited) {
            q.push(cur / 2);
            visited[cur / 2] = {true, cur};
        }
        if (!visited[cur - 1].visited) {
            q.push(cur - 1);
            visited[cur - 1] = {true, cur};
        }
    }
}

void solution() {
    bfs();

    int cur = 1;
    do {
        answer.push(cur);
        cur = visited[cur].from;
    }while(visited[cur].from != 0);
    if (N != 1)
        answer.push(N);
}

void output() {
    cout << answer.size() - 1 << '\n';
    while (!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
