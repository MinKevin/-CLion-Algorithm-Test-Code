#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> reverseNumber(10, 0);
long long answer;

void input() {
    cin >> N;
    answer = 0;
}

void solution() {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        reverseNumber[9 - i] = 1;

        do {
            if (counter < N) {
                counter++;
                continue;
            }

            for (int j = 0; j < 10; j++) {
                if (reverseNumber[j]) {
                    answer = answer * 10 + (9 - j);
                }
            }
            return;

        } while (next_permutation(reverseNumber.begin(), reverseNumber.end()));
    }
    answer = -1;
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
