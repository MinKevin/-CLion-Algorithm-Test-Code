#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 10000

using namespace std;

int T;
vector<int> N;
vector<bool> numbers;
vector<pair<int, int>> answers;

void input() {
    numbers = vector(MAX_NUM + 1, true);

    cin >> T;

    int n;
    for (int t = 0; t < T; t++) {
        cin >> n;
        N.push_back(n);
    }
}

void solution() {
    for (int i = 2; i <= sqrt(MAX_NUM); i++) {
        if (numbers[i]) {
            for (int j = i * i; j <= MAX_NUM; j += i) {
                numbers[j] = false;
            }
        }
    }

    for (int t = 0; t < T; t++) {
        int st = N[t] / 2;
        int en = N[t] / 2;

        while(true) {
            while (!numbers[st]) {
                st--;
            }

            while (!numbers[en]) {
                en++;
            }

            int sum = st + en;
            if (sum == N[t]) {
                answers.push_back({st, en});
                break;
            }
            if (sum < N[t]) {
                en++;
            } else {
                st--;
            }
        }
    }
}

void output() {
    for (pair<int, int> answer : answers)
        cout << answer.first << ' ' << answer.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
