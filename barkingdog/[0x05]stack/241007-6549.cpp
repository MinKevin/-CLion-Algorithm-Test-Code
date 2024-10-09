#include "../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

ostringstream oss;

vector<int> n;
vector<vector<ll> > h;
stack<pair<ll, ll> > s;

void input() {
    do {
        int nBuf;
        cin >> nBuf;
        n.push_back(nBuf);

        vector<ll> hBuf(nBuf, 0);
        for (int i = 0; i < nBuf; i++) {
            cin >> hBuf[i];
        }
        h.push_back(hBuf);
    } while (n.back() != 0);
    n.pop_back();
}

void solution() {
    for (int i = 0; i < n.size(); i++) {
        ll answer = 0;
        for (int j = 0; j < n[i]; j++) {
            while (!s.empty() && s.top().first > h[i][j]) {
                pair<ll, ll> cur = s.top();
                s.pop();

                ll area;
                if (s.empty()) {
                    area = cur.first * j;
                } else {
                    area = cur.first * (j - (s.top().second + 1));
                }
                if (area > answer) {
                    answer = area;
                }
            }
            s.push({h[i][j], j});
        }

        while (!s.empty()) {
            pair<ll, ll> cur = s.top();
            s.pop();

            ll area;
            if (s.empty()) {
                area = cur.first * n[i];
            } else {
                area = cur.first * (n[i] - (s.top().second + 1));
            }
            if (area > answer) {
                answer = area;
            }
        }
        oss << answer << '\n';
    }
}

void output() {
    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    streambuf *p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(p_cout_streambuf);
    output();
}
