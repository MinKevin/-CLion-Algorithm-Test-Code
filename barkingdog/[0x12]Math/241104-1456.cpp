#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long A, B;
vector<bool> numbers;
long long answer;
long long answerMinus;

void input() {
    cin >> A >> B;
    numbers = vector(sqrt(B) + 1, true);
    answer = 0;
    answerMinus = 0;
}

void solution() {
    numbers[1] = false;
    for (int i = 2; i <= sqrt(B); i++) {
        if (numbers[i]) {
            for (int j = 2; i * j <= sqrt(B); j++) {
                numbers[i * j] = false;
            }
        }
    }

    for (int i = 2; i <= sqrt(B); i++) {
        if (numbers[i]) {
            long long exValue = (long long)i * i;
            while(exValue <= B) {
                if(exValue < A) {
                    answerMinus++;
                }
                answer++;
                if (exValue > LONG_LONG_MAX / i)
                    break;
                exValue *= i;
            }
        }
    }
}

void output() {
    cout << answer - answerMinus;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
