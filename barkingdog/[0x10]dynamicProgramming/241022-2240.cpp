#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct movedAndAteCounter {
    int loc;
    int moved;
    int ate;
};

struct cmp {
    bool operator()(movedAndAteCounter a, movedAndAteCounter b) {
        return a.ate != b.ate ? a.ate < b.ate : a.moved > b.moved;
    }
};

int T, W;
vector<int> board;
priority_queue<movedAndAteCounter, vector<movedAndAteCounter>, cmp> pq;
int answer;

void input() {
    cin >> T >> W;
    board = vector(T + 1, 0);

    for (int i = 0; i < T; i++) {
        cin >> board[i];
    }
}

void solution() {
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        movedAndAteCounter cur = pq.top();
        pq.pop();
        if (cur.loc == T) {
            if (answer < cur.ate)
                answer = cur.ate;
            continue;
        }

        if (cur.moved % 2 == 0) {
            if (board[cur.loc] == 1) {
                pq.push({cur.loc + 1, cur.moved, cur.ate + 1});
            } else {
                if (cur.moved < W) {
                    pq.push({cur.loc + 1, cur.moved + 1, cur.ate + 1});
                }
                pq.push({cur.loc + 1, cur.moved, cur.ate});
            }
        } else {
            if (board[cur.loc] == 2) {
                pq.push({cur.loc + 1, cur.moved, cur.ate + 1});
            } else {
                if (cur.moved < W) {
                    pq.push({cur.loc + 1, cur.moved + 1, cur.ate + 1});
                }
                pq.push({cur.loc + 1, cur.moved, cur.ate});
            }
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
