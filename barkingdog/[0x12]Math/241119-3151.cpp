#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> As;
long long answer;

void input() {
    cin >> N;
    As = vector(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }
}

int upperBound(vector<int>::iterator st, vector<int>::iterator en, int target) {
    while (st < en) {
        int mid = (en - st) / 2;

        if (*(st + mid) <= target) {
            st += mid + 1;
        } else {
            en = st + mid;
        }
    }
    return en - As.begin();
}

int lowerBound(vector<int>::iterator st, vector<int>::iterator en, int target) {
    while (st < en) {
        int mid = (en - st) / 2;

        if (*(st + mid) < target) {
            st += mid + 1;
        } else {
            en = st + mid;
        }
    }
    return en - As.begin();
}

void solution() {
    sort(As.begin(), As.end(), less());

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            answer += upperBound(As.begin() + j + 1, As.end(), -(As[i] + As[j]))
                    - lowerBound(As.begin() + j + 1, As.end(), -(As[i] + As[j]));
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
