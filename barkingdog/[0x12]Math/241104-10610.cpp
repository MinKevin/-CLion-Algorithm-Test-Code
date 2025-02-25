#include <cmath>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

string N;
vector<int> numberCounter;
string answer;

void input() {
    cin >> N;
    numberCounter = vector(10, 0);
}

void solution() {
    for (int i = 0; i < N.size(); i++) {
        numberCounter[N[i] - '0']++;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += numberCounter[i] * i;
    }

    if (sum % 3 != 0 || numberCounter[0] == 0)
        answer = "-1";
    else {
        for (int i = 9; i >= 0; i--) {
            while (numberCounter[i] != 0) {
                answer.append(to_string(i));
                numberCounter[i]--;
            }
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
