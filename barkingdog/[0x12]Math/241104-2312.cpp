#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 100000

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
    numbers[1] = false;
    for (int i = 2; i <= sqrt(MAX_NUM); i++) {
        if (numbers[i]) {
            for (int j = i * i; j <= MAX_NUM; j += i) {
                numbers[j] = false;
            }
        }
    }

    for (int t = 0; t < T; t++) {
        for (int i = 2; i <= N[t]; i++) {
            if (N[t] % i == 0) {
                int counter = 0;
                while (N[t] % i == 0) {
                    counter++;
                    N[t] /= i;
                }
                answers.push_back({i, counter});

                if (N[t] == 1)
                    break;
            }
        }
    }
}

void output() {
    for (pair<int, int> answer : answers) {
        cout << answer.first << ' ' << answer.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
