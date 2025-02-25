#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 1000000

using namespace std;

int T;
vector<int> N;
vector<bool> numbers;
vector<int> answers;

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
        int answer = 0;

        int st = 1;
        int en = N[t];
        while(st <= en) {
            while (!numbers[st]) {
                st++;
            }
            while(!numbers[en]) {
                en--;
            }
            int sum = st + en;
            if (sum == N[t]) {
                answer++;
                st++;
            } else if (sum < N[t]) {
                st++;
            } else {
                en--;
            }
        }

        answers.push_back(answer);
    }
}

void output() {
    for (int answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
