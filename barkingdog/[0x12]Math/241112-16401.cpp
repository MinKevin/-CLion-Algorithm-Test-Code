#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int M, N;
vector<int> snacksLength;
int answer;

void input() {
    cin >> M >> N;
    snacksLength = vector(N, 0);

    for (int i = 0; i < N; i++)
        cin >> snacksLength[i];
}

ll maxNephew(int criteria) {
    ll count = 0;
    for (int snackLength : snacksLength)
        count += snackLength / criteria;

    return count;
}

void solution() {
    sort(snacksLength.begin(), snacksLength.end(), less());

    int st = 0;
    int en = 1'000'000'000;
    while (st < en) {
        int mid = (st + en + 1) / 2;

        if (maxNephew(mid) >= M)
            st = mid;
        else
            en = mid - 1;
    }
    answer = st;
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
