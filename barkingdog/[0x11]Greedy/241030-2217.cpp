#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ropes;
int answer;
void input() {
    cin >> N;

    int length;
    for (int i = 0; i < N; i++) {
        cin >> length;
        ropes.push_back(length);
    }
}

void solution() {
    sort(ropes.begin(), ropes.end(), greater());

    for (int i = 1; i <= ropes.size(); i++) {
        if (ropes[i - 1] * i > answer)
            answer = ropes[i - 1] * i;
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
