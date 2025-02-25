#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int An, Bn;
vector<int> A;
vector<int> B;
vector<int> answers;

void input() {
    cin >> An >> Bn;
    A = vector(An, 0);
    B = vector(Bn, 0);

    for (int i = 0; i < An; i++)
        cin >> A[i];

    for (int i = 0; i < Bn; i++)
        cin >> B[i];
}

bool binarySearch(int target) {
    int st = 0;
    int en = B.size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;

        if (B[mid] > target)
            en = mid - 1;
        else if (B[mid] < target)
            st = mid + 1;
        else
            return true;
    }

    return false;
}

void solution() {
    sort(A.begin(), A.end(), less());
    sort(B.begin(), B.end(), less());

    for (int i = 0; i < A.size(); i++) {
        if (!binarySearch(A[i]))
            answers.push_back(A[i]);
    }
}

void output() {
    cout << answers.size() << '\n';

    for (int answer : answers)
        cout << answer << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
