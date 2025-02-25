#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
int answer;

void input() {
    cin >> N;
    v.clear();
    answer = 0;

    int S, W;
    for (int i = 0; i < N; i++) {
        cin >> S >> W;
        v.push_back({S, W});
    }
}

void dfs(int loc, int brokenEggCnt, vector<pair<int, int>> eggData) {
    if (brokenEggCnt > answer)
        answer = brokenEggCnt;

    if (loc == N)
        return;

    if (eggData[loc].first <= 0) {
        dfs(loc + 1, brokenEggCnt, eggData);
    }

    else {
        for (int i = 0; i < N; i++) {
            if (i == loc || eggData[i].first <= 0)
                continue;

            int innerBrokenEggCnt = 0;
            vector<pair<int, int> > eggDataDuplicated = eggData;
            eggDataDuplicated[loc].first -= eggDataDuplicated[i].second;
            eggDataDuplicated[i].first -= eggDataDuplicated[loc].second;

            if (eggDataDuplicated[loc].first <= 0)
                innerBrokenEggCnt++;
            if (eggDataDuplicated[i].first <= 0)
                innerBrokenEggCnt++;

            dfs(loc + 1, brokenEggCnt + innerBrokenEggCnt, eggDataDuplicated);
        }
    }
}

void solution() {
    dfs(0, 0, v);
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
