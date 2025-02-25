#include <sstream>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int T;
vector<int> a, b;
vector<ll> answers;

void input() {
    cin >> T;

    a = vector(T, 0);
    b = vector(T, 0);
    for (int t = 0; t < T; t++) {
        cin >> a[t] >> b[t];
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
void solution() {
    for (int t = 0; t < T; t++) {
        answers.push_back(lcm(a[t], b[t]));
    }
}

void output() {
    for (ll answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
