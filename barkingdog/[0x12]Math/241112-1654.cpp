#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int K, N;
vector<int> lengths;
int answer;

void input() {
    cin >> K >> N;
    lengths = vector(K, 0);

    for (int i = 0; i < K; i++) {
        cin >> lengths[i];
    }
}

long long cutRopes(long long length) {
    long long sum = 0;

    for (int i = 0; i < lengths.size(); i++) {
        sum += lengths[i] / length;
    }

    return sum;
}

void solution() {
    long long st = 0;
    long long en = INT_MAX;
    while (st <= en) {
        long long mid = (st + en) / 2;

        if (cutRopes(mid) >= N)
            st = mid + 1;
        else
            en = mid - 1;
    }

    answer = st - 1;
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
