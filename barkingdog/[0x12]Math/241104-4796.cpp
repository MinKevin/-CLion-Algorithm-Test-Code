#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct inp {
    int l;
    int p;
    int v;
};

int L, P, V;
vector<int> answers;
vector<inp> inps;

void input() {
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        inps.push_back({ L, P, V });
    }
}

void solution() {

    for (int i = 0; i < inps.size(); i++) {
        int answer = 0;
        answer += inps[i].l * (inps[i].v / inps[i].p);
        answer += min(inps[i].v % inps[i].p, inps[i].l);
        answers.push_back(answer);
    }

}

void output() {
    for (int i = 0; i < answers.size(); i++) {
        cout << "Case " << i + 1 << ": " << answers[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
