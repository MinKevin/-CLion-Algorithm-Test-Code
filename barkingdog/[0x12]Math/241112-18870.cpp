#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
vector<int> questions;
vector<int> answers;

void input() {
    cin >> N;

    int inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        numbers.push_back(inp);
        questions.push_back(inp);
    }
}

int binarySearch(int target) {
    int st = 0;
    int en = numbers.size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (target < numbers[mid])
            en = mid;
        else if (target == numbers[mid])
            return mid;
        else
            st = mid + 1;
    }
    return -1;
}

void solution() {
    sort(numbers.begin(), numbers.end(), less());
    vector<int> numbersBuf;

    int exNumber = 2000000000;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != exNumber) {
            numbersBuf.push_back(numbers[i]);
        }
        exNumber = numbers[i];
    }
    numbers = numbersBuf;

    for (int i = 0; i < questions.size(); i++) {
        answers.push_back(binarySearch(questions[i]));
    }
}

void output() {
    for (int answer : answers)
        cout << answer << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
