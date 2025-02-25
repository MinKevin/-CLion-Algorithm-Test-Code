#include <sstream>
#include <iostream>

using namespace std;

long long N;
long long answer;
void input() {
    cin >> N;
}

void solution() {
    answer = 4 * N;

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
