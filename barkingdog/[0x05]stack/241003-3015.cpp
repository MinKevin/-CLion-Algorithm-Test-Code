#include "../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> inp;
stack<pair<int, int>> s;
long long ans = 0;

void input() {
    cin >> N;

    inp.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top().first < inp[i]) {
            ans += s.top().second;
            s.pop();
        }

        if (!s.empty() && s.top().first == inp[i]) {
            ans += s.top().second++;
            if (s.size() >= 2)
                ans++;
        } else {
            if (!s.empty())
                ans++;
            s.push({inp[i], 1});
        }
    }
}

void output() {
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
