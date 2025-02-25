#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
vector<int> sum;
int answer;

void input() {
    cin >> N;

    int inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        numbers.push_back(inp);
    }
}

bool binarySearch(int target) {
    int st = 0;
    int en = sum.size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;

        if (target < sum[mid])
            en = mid - 1;
        else if (target == sum[mid])
            return true;
        else
            st = mid + 1;
    }

    return false;
}

void solution() {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            sum.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(numbers.begin(), numbers.end(), less());
    sort(sum.begin(), sum.end(), less());

    for (int i = numbers.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            int result = numbers[i] - numbers[j];
            if (binarySearch(result)) {
                answer = numbers[i];
                return;
            }
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
