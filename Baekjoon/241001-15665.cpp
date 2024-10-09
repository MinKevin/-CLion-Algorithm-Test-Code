#include "../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<int> inp;
vector<bool> vis(10, false);
vector<int> ans;
ostringstream oss;

void input() {
    inp.clear();
    vis = vector<bool>(10, false);
    ans.clear();
    oss.str("");
    oss.clear();

    cin >> N >> M;

    int inpNum = 0;
    for (int i = 0; i < N; i++) {
        cin >> inpNum;
        if (vis[inpNum] == false) {
            vis[inpNum] = true;
            inp.push_back(inpNum);
        }
    }
}

void recursive(int st, int depth) {
    if (depth == M) {
        string ansBuf;
        for (int val : ans) {
            oss << val << " ";
        }
        oss << "\n";
        return;
    }
    for (int i = st; i < inp.size(); i++) {
        ans.push_back(inp[i]);
        recursive(0, depth + 1);
        ans.pop_back();
    }
}

void solution() {
    sort(inp.begin(), inp.end());
    recursive(0, 0);
}

void output() {


    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    streambuf* p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(p_cout_streambuf);
    output();
}
