#include "../algorithm-frame.h"
#include <iostream>

using namespace std;

int x, y, result;

int sum(int a, int b) {
    return a + b;
}

void input() {
    cin >> x >> y;
}

void solution() {
    result = x + y;
}

void output() {
    cout << result << endl;
}
