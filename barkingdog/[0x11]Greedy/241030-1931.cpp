#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct timeInfo {
    int st;
    int en;
};

struct cmp {
    bool operator() (timeInfo a, timeInfo b) const {
        return a.en == b.en ? a.st < b.st : a.en < b.en;
    }
};

int N;
vector<timeInfo> timeInfos;
int answer;

void input() {
    cin >> N;

    int st, en;
    for (int i = 0; i < N; i++) {
        cin >> st >> en;
        timeInfos.push_back({st, en});
    }
}

void solution() {
    sort(timeInfos.begin(), timeInfos.end(), cmp());

    int cursor = 0;
    for (timeInfo element : timeInfos) {
        if (element.st >= cursor) {
            cursor = element.en;
            answer++;
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
