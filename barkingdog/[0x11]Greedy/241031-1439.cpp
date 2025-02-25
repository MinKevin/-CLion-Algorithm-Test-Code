#include <sstream>
#include <iostream>

using namespace std;

string str;
int answer;
void input() {
    cin >> str;
    answer = 0;
}

void solution() {
    int st = 0;
    int en = str.length() - 1;
    int eraseNumber = str[0];
    while (st <= en) {
        while (st < str.length() && str[st] == eraseNumber) {
            st++;
        }
        while (en >= 0 && str[en] == eraseNumber) {
            en--;
        }

        if (st > en)
            return;

        if (eraseNumber == '0')
            eraseNumber = '1';
        else
            eraseNumber = '0';
        answer++;
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
