#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, T;
vector<int> A;
vector<int> B;
vector<int> sumB;

long long answer;

void input() {
    cin >> T;

    cin >> n;
    A = vector(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    B = vector(m, 0);

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
}

long long upperBound(vector<int>::iterator st, vector<int>::iterator en, int target) {
    while (st < en) {
        int mid = (en - st) / 2;

        if (*(st + mid) <= target) {
            st += mid + 1;
        } else {
            en = st + mid;
        }
    }
    return en - sumB.begin();
}

long long lowerBound(vector<int>::iterator st, vector<int>::iterator en, int target) {
    while (st < en) {
        int mid = (en - st) / 2;

        if (*(st + mid) < target) {
            st += mid + 1;
        } else {
            en = st + mid;
        }
    }
    return en - sumB.begin();
}

void solution() {
    for (int i = 0; i < B.size(); i++) {
        int sum = 0;
        for (int j = i; j < B.size(); j++) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end(), less());

    for (int i = 0; i < A.size(); i++) {
        int sumA = 0;
        for (int j = i; j < A.size(); j++) {
            sumA += A[j];
            answer += upperBound(sumB.begin(), sumB.end(), T - sumA)
                    - lowerBound(sumB.begin(), sumB.end(), T - sumA);
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
