#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
int answer;

void input() {
    cin >> N;
    numbers = vector(N, 0);

    for (int i = 0; i < N; i++)
        cin >> numbers[i];
}

void solution() {
    sort(numbers.begin(), numbers.end(), less());

    for (int i = 0; i < numbers.size(); i++) {
        int st = 0;
        int en = numbers.size() - 1;
        bool findGood = false;
        while (st < en) {
            if (st == i) {
                st++;
                continue;
            }
            if (en == i) {
                en--;
                continue;
            }

            if (numbers[st] + numbers[en] < numbers[i])
                st++;
            else if (numbers[st] + numbers[en] == numbers[i]) {
                findGood = true;
                break;
            }
            else
                en--;
        }

        if (findGood)
            answer++;
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
