#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

#define MAX_NUM 1000000

using namespace std;

int N;
vector<bool> primeNumbers(MAX_NUM * 2 + 1, true);
int answer;

void input() {
    cin >> N;
}

bool palindrome(int number) {
    string stringNumber = to_string(number);
    for (int i = 0; i < stringNumber.size() / 2; i++) {
        if (stringNumber[i] != stringNumber[stringNumber.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void solution() {
    primeNumbers[1] = false;
    for (int i = 2; i <= MAX_NUM * 2; i++) {
        if (primeNumbers[i]) {
            if (!palindrome(i))
                primeNumbers[i] = false;
            for (int j = 2; i * j <= MAX_NUM * 2; j++) {
                primeNumbers[i * j] = false;
            }
        }
    }

    for (int i = N; i <= MAX_NUM * 2; i++) {
        if (primeNumbers[i]) {
            answer = i;
            break;
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
