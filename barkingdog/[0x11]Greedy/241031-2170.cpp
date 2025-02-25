#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> lines;
priority_queue<int, vector<int>, greater<>> pq;
long long answer;
void input() {
    cin >> N;
    lines = vector<pair<int, int>>(N);

    int st, en;
    for (int i = 0; i < N; i++) {
        cin >> st >> en;
        lines[i] = {st, en};
    }
}

void solution() {
    sort(lines.begin(), lines.end(), less());

    int st = lines[0].first;
    int en = lines[0].second;
    for (int i = 1; i < lines.size(); i++) {
        if (lines[i].first > en) {
            answer += (en - st);
            st = lines[i].first;
            en = lines[i].second;
        } else if (lines[i].second > en) {
            en = lines[i].second;
        }
    }
    answer += en - st;
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
