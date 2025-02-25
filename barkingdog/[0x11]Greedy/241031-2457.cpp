#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct periodInfo {
    int st;
    int en;
};

struct cmp {
    bool operator()(periodInfo a, periodInfo b) const {
        return a.st == b.st ? a.en < b.en : a.st < b.st;
    }
};

int N;
vector<periodInfo> periods;
int answer = 0;
bool possible = false;

void input() {
    cin >> N;

    int st1, st2, en1, en2;
    for (int i = 0; i < N; i++) {
        cin >> st1 >> st2 >> en1 >> en2;
        periods.push_back({st1 * 100 + st2, en1 * 100 + en2});
    }
}

void solution() {
    sort(periods.begin(), periods.end(), cmp());

    int minBoundary = 0;
    int maxBoundary = 301;
    for (int i = 0; i < periods.size(); i++) {
        if (periods[i].st <= minBoundary && periods[i].en > maxBoundary) {
            maxBoundary = periods[i].en;
        } else if (periods[i].st > minBoundary) {
            if (periods[i].st > maxBoundary)
                return;

            if (periods[i].en > maxBoundary) {
                minBoundary = maxBoundary;
                maxBoundary = periods[i].en;
                answer++;
            }
        }

        if (maxBoundary >= 1201) {
            possible = true;
            return;
        }
    }
}

void output() {
    if (possible)
        cout << answer;
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
