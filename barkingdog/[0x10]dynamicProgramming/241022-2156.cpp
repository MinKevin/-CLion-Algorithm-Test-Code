#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> amounts;
vector<vector<int> > dpCounter;
int answer;

void input() {
    cin >> N;
    amounts = vector<int>(N);
    dpCounter = vector(2, vector(N, 0));
    answer = 0;

    for (int i = 0; i < N; i++)
        cin >> amounts[i];
}

void solution() {
    dpCounter[1][0] = 0;
    dpCounter[0][0] = amounts[0];
    answer = amounts[0];

    for (int i = 1; i < N; i++) {
        int exMaximum = 0;
        for (int j = i - 2; j >= 0; j--) {
            if (exMaximum < max(dpCounter[0][j], dpCounter[1][j]))
                exMaximum = max(dpCounter[0][j], dpCounter[1][j]);
        }

        dpCounter[0][i] = exMaximum + amounts[i];
        dpCounter[1][i] = dpCounter[0][i - 1] + amounts[i];

        if (answer < max(dpCounter[0][i], dpCounter[1][i]))
            answer = max(dpCounter[0][i], dpCounter[1][i]);
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
