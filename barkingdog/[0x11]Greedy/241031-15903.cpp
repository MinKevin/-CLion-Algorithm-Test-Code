#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<>> pq;
long long answer;
void input() {
    cin >> n >> m;
    answer = 0;

    int inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        pq.push(inp);
    }
}

void solution() {
    while(m--) {
        long long nextValue = 0;
        nextValue += pq.top();
        pq.pop();
        nextValue += pq.top();
        pq.pop();

        pq.push(nextValue);
        pq.push(nextValue);
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
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
