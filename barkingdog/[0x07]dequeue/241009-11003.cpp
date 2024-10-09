#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

ostringstream oss;

int N, L;
vector<int> nums;

void input() {
    cin >> N >> L;

    nums.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
}

struct A {
    int pos;
    int data;
};

void solution() {
    deque<A> dq;
    for (int i = 0; i < N; i++) {
        while(!dq.empty() && dq.back().data >= nums[i]) {
            dq.pop_back();
        }
        while(!dq.empty() && dq.front().pos <= i - L) {
            dq.pop_front();
        }
        dq.push_back({i, nums[i]});

        oss << dq.front().data << ' ';
    }
}

void output() {
    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    streambuf *pCoutStreamBuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(pCoutStreamBuf);
    output();
}
