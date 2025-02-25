#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct classTimeInfo {
    int st;
    int en;
};

struct cmp {
    bool operator()(classTimeInfo a, classTimeInfo b) const {
        return a.st == b.st ? a.en < b.en : a.st < b.st;
    }
};

int N;
vector<classTimeInfo> classes;
int answer;
priority_queue<int, vector<int>, greater<>> pq;

void input() {
    cin >> N;

    int st, en;
    for (int i = 0; i < N; i++) {
        cin >> st >> en;
        classes.push_back({st, en});
    }
}

void solution() {
    sort(classes.begin(), classes.end(), cmp());

    for (int i = 0; i < classes.size(); i++) {
        pq.push(classes[i].en);
        if (pq.top() <= classes[i].st) {
            pq.pop();
        }
    }
}

void output() {
    cout << pq.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
