#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> attributes;
int answer1, answer2;

void input() {
    cin >> N;
    attributes = vector(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> attributes[i];
    }
}

void solution() {
    sort(attributes.begin(), attributes.end(), less());

    int st = 0;
    int en = attributes.size() - 1;
    answer1 = attributes[st];
    answer2 = attributes[en];
    while (st < en) {
        if (abs(attributes[st] + attributes[en]) <= abs(answer1 + answer2)) {
            answer1 = attributes[st];
            answer2 = attributes[en];
        }

        if (attributes[st] + attributes[en] < 0) {
            st++;
        } else if (attributes[st] + attributes[en] > 0) {
            en--;
        } else {
            break;
        }
    }
}

void output() {
    cout << answer1 << ' ' << answer2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
