#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, M;
vector<int> treeHeights;
int answer;

void input() {
    cin >> N >> M;
    treeHeights = vector(N, 0);

    for (int i = 0; i < N; i++)
        cin >> treeHeights[i];
}

ll getWood(int height) {
    ll count = 0;
    for (int i = 0; i < treeHeights.size(); i++) {
        count += treeHeights[i] - height <= 0 ? 0 : treeHeights[i] - height;
    }

    return count;
}

void solution() {
    sort(treeHeights.begin(), treeHeights.end(),less());

    int st = 0;
    int en = 1'000'000'000;
    while (st < en) {
        int mid = (st + en + 1) / 2;

        if (getWood(mid) >= M)
            st = mid;
        else
            en = mid - 1;
    }

    answer = en;
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
