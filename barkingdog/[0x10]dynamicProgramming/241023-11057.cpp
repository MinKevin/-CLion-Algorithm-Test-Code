#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dpCounter;
int answer;

void input() {
    cin >> N;
    dpCounter = vector(10, vector(N + 1, -1));
    answer = 0;

}

int dpFunction(int num, int cnt) {
    if (dpCounter[num][cnt] != -1)
        return dpCounter[num][cnt];
    if (num == 0)
        return dpCounter[num][cnt] = dpFunction(num, cnt - 1) % 10007;
    return dpCounter[num][cnt] = (dpFunction(num - 1, cnt) + dpFunction(num, cnt - 1)) % 10007;
}

void solution() {
    for (int i = 0; i < 10; i++) {
        dpCounter[i][0] = 1;
    }
    for (int i = 0; i < 10; i++)
        answer += dpFunction(i, N - 1);
}

void output() {
    cout << answer % 10007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
