#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct scope {
    int st;
    int en;
};

int T;
vector<scope> scopes;
vector<bool> board(10000, true);
vector<int> visited;
vector<int> primeNumbers;
vector<int> answers;

void input() {
    cin >> T;

    int st, en;
    for (int t = 0; t < T; t++) {
        cin >> st >> en;
        scopes.push_back({st, en});
    }
}

void solution() {
    for (int i = 2; i < 10000; i++) {
        if (board[i]) {
            if (i >= 1000)
                primeNumbers.push_back(i);

            for (int j = 2; i * j < 10000; j++) {
                board[i * j] = false;
            }
        }
    }

    for (int t = 0; t < T; t++) {
       queue<int> q;
        q.push(scopes[t].st);
        visited = vector(10000, -1);
        visited[scopes[t].st] = 0;

        bool possible = false;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == scopes[t].en) {
                answers.push_back(visited[cur]);
                possible = true;
                break;
            }

            int buffer = cur;
            for (int i = 1; i < 10000; i *= 10) {
                int criteria = buffer % 10;
                buffer /= 10;

                for (int j = 0; j < 10; j++) {
                    if (cur + i * (j - criteria) < 1000)
                        continue;

                    if (board[cur + i * (j - criteria)] && visited[cur + i * (j - criteria)] == -1) {
                        visited[cur + i * (j - criteria)] = visited[cur] + 1;
                        q.push(cur + i * (j - criteria));
                    }
                }
            }
        }
        if (!possible) {
            answers.push_back(-1);
        }
    }
}

void output() {
    for (int answer : answers) {
        if (answer != -1)
            cout << answer << '\n';
        else
            cout << "Impossible\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
