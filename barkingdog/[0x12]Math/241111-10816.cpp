#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<pair<int, int> > numbersCounter;
vector<int> questions;
vector<int> answers;

void input() {
    cin >> N;

    int inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        numbers.push_back(inp);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> inp;
        questions.push_back(inp);
    }
}

int binarySearch(int target) {
    int st = 0;
    int en = numbersCounter.size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;

        if (numbersCounter[mid].first < target)
            st = mid + 1;
        else if (numbersCounter[mid].first == target)
            return numbersCounter[mid].second;
        else
            en = mid - 1;
    }

    return 0;
}

void solution() {
    sort(numbers.begin(), numbers.end(), less());

    for (int i = 0; i < numbers.size(); i++) {
        if (numbersCounter.empty()) {
            numbersCounter.push_back({numbers[i], 1});
        } else {
            if (numbersCounter.back().first == numbers[i]) {
                numbersCounter.back().second++;
            } else {
                numbersCounter.push_back({numbers[i], 1});
            }
        }
    }

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
