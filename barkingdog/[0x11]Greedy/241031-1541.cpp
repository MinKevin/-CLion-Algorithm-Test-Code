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
    bool parentheses = false;
    string tmp = "";
    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (parentheses)
                answer -= stoi(tmp);
            else
                answer += stoi(tmp);
            tmp = "";

            if (str[i] == '-')
                parentheses = true;
        } else {
            tmp += str[i];
        }
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
