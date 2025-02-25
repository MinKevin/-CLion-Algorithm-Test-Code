#include <sstream>
#include <iostream>
#include <climits>

#define ll long long

using namespace std;

ll N, A, B, C, D;
ll answer = LONG_LONG_MAX;

void input() {
    cin >> N >> A >> B >> C >> D;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solution() {
    if (A * D < B * C) {
        swap(A, C);
        swap(B, D);
    }

    ll lcmResult = lcm(A, C);
    for (ll i = 0; i < lcmResult / C; i++) {
        ll sum = D * i;
        if (N - C * i > 0)
            sum += ((N - C * i - 1) / A + 1) * B;

        if (sum < answer)
            answer = sum;
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
