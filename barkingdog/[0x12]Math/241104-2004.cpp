#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct numberCounter {
    ll two;
    ll five;
};

ll n, m;
vector<numberCounter> dp;
ll answer;

void input() {
    cin >> n >> m;
}

numberCounter numberCountFunction(ll number) {
    ll two = 0;
    ll five = 0;

    for (ll i = 2; i <= number; i *= 2) {
        two += number / i;
    }

    for (ll i = 5; i <= number; i *= 5) {
        five += number / i;
    }

    return {two, five};
}

void solution() {
    numberCounter resultOfn = numberCountFunction(n);
    numberCounter resultOfm = numberCountFunction(m);
    numberCounter resultOfnMinusm = numberCountFunction(n-m);

    ll twoCount = resultOfn.two - resultOfm.two - resultOfnMinusm.two;
    ll fiveCount = resultOfn.five - resultOfm.five - resultOfnMinusm.five;

    answer = min(twoCount, fiveCount);
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
