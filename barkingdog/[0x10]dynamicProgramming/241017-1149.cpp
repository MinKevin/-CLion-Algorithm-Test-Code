#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > houses;
vector<vector<int> > dpCounter;
int answer;

void input() {
    cin >> N;
    houses = vector(3, vector<int>(N));
    dpCounter = vector(3, vector(N, -1));

    for (int i = 0; i < N; i++) {
        cin >> houses[0][i] >> houses[1][i] >> houses[2][i];
    }
}

int dpFunction(int color, int loc) {
    if (loc >= N)
        return 0;

    if (dpCounter[color][loc] == -1) {
        for (int i = 0; i < 3; i++) {
            if (color != i &&
                (dpCounter[color][loc] == -1 || dpCounter[color][loc] > dpFunction(i, loc + 1))) {
                dpCounter[color][loc] = dpFunction(i, loc + 1);
            }
        }
        dpCounter[color][loc] += houses[color][loc];
    }

    return dpCounter[color][loc];
}

void solution() {
    dpCounter[0][N - 1] = houses[0][N - 1];
    dpCounter[1][N - 1] = houses[1][N - 1];
    dpCounter[2][N - 1] = houses[2][N - 1];

    dpFunction(0, 0);
    dpFunction(1, 0);
    dpFunction(2, 0);

    answer = min(min(dpCounter[0][0], dpCounter[1][0]), dpCounter[2][0]);
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
