#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;
int answer;

void input() {
    cin >> N;
    nums = vector(N, 0);
    answer = 0;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
}

void solution() {
    sort(nums.begin(), nums.end(), less());
    int cur = 0;
    while (cur < nums.size() && nums[cur] <= 0) {
        if (cur + 1 < nums.size() && nums[cur + 1] <= 0) {
            answer += nums[cur] * nums[cur + 1];
            cur += 2;
        } else {
            answer += nums[cur];
            cur++;
        }
    }

    cur = nums.size() - 1;
    while (cur >= 0 && nums[cur] > 0) {
        if (cur - 1 >= 0 && nums[cur - 1] != 1 && nums[cur - 1] > 0) {
            answer += nums[cur] * nums[cur - 1];
            cur -= 2;
        } else {
            answer += nums[cur];
            cur--;
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
