#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string N;
vector<vector<int> > digitAndNumberCount;
vector<int> answer;

void input() {
    cin >> N;
    digitAndNumberCount = vector(N.size() + 1, vector(2, 0));
    answer = vector(10, 0);
}

void solution() {
    for (int i = 1; i <= N.size(); i++) {
        digitAndNumberCount[i][1] = digitAndNumberCount[i - 1][1] * 10 + pow(10, i - 1);
        digitAndNumberCount[i][0] = digitAndNumberCount[i][1];
        int buf = i;
        while (buf--) {
            digitAndNumberCount[i][0] -= pow(10, buf);
        }
    }

    for (int i = 1; i <= N.size(); i++) {
        for (int j = 1; j <= N[N.size() - i] - '0'; j++) {
            answer[j] += pow(10, i - 1);
            answer[0] += digitAndNumberCount[i - 1][0];
            for (int k = 1; k < i; k++) {
                answer[0] += pow(10, k - 1);
            }

            for (int k = 1; k < 10; k++) {
                answer[k] += digitAndNumberCount[i - 1][1];
            }
        }
        if (i >= 2) {
            int num1 = 0;
            for (int j = 0; j < i - 1; j++) {
                num1 = num1 * 10 + (9 - (N[N.size() - i + 1 + j] - '0'));
            }
            answer[N[N.size() - i] - '0'] -= num1;
        }
    }
}

void output() {
    for (int ans: answer)
        cout << ans << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}

// 1 1*10+10=20 20*10+100
