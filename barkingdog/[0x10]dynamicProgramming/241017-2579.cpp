#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> stairScore;
vector<vector<int> > dpCounter;
int answer;

void input() {
    cin >> N;
    stairScore = vector(N, 0);
    dpCounter = vector(2, vector(N, -1));
    answer = 0;

    for (int i = 0; i < N; i++) {
        cin >> stairScore[i];
    }
}

int dpFunction(bool jump, int loc) {
    if (loc >= N)
        return 0;

    if (dpCounter[jump][loc] == -1) {
        if (!jump)
            dpCounter[0][loc] = stairScore[loc] + dpFunction(true, loc + 2);
        else
            dpCounter[1][loc] = stairScore[loc] + max(dpFunction(false, loc + 1), dpFunction(true, loc + 2));
    }
    return dpCounter[jump][loc];
}

void solution() {
    dpCounter[0][N - 1] = stairScore[N - 1];
    dpCounter[1][N - 1] = stairScore[N - 1];
    dpCounter[0][N - 2] = 0;
    dpFunction(true, 1);
    dpFunction(true, 0);
    if (N > 1)
        answer = max(dpCounter[1][0], dpCounter[1][1]);
    else
        answer = dpCounter[1][0];
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
