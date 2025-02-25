#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> questions;
vector<int> answers;

void input() {
    cin >> N;

    numbers = vector(N, 0);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    cin >> M;

    questions = vector(M, 0);
    for (int i = 0; i < M; i++)
        cin >> questions[i];
}

int binarySearch(int target) {
    int st = 0;
    int en = N - 1;
    while(st <= en) {
        int mid = (st + en) / 2;
        if (target > numbers[mid])
            st = mid + 1;
        else if (target == numbers[mid]) {
            return 1;
        } else {
            en = mid - 1;
        }
    }
    return 0;
}

void solution() {
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < M; i++) {
        answers.push_back(binarySearch(questions[i]));
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
