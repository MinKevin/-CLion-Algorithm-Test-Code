#include <sstream>
#include <iostream>

using namespace std;

int A, B;
int answer;

void input() {
    cin >> A >> B;
}

int function(int number) {
    int i = 1;
    int sum = 0;

    while (i < number) {
        sum += i * i;
        number -= i++;
    }

    return sum += i * number;
}

void solution() {
    answer = function(B) - function(A - 1);
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
