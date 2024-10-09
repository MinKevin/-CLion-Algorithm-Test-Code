#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

ostringstream oss;

int T;
vector<string> orders;
vector<deque<int> > deques;

void input() {
    cin >> T;
    while (T--) {
        string order;
        int size;
        string input;
        deque<int> dq;
        cin >> order >> size >> input;

        string numBuf;
        for (char ch: input) {
            if (ch == '[') {
            } else if (ch == ',' || ch == ']') {
                if (numBuf != "")
                    dq.push_back(stoi(numBuf));
                numBuf = "";
            } else {
                numBuf += ch;
            }
        }

        orders.push_back(order);
        deques.push_back(dq);
    }
}

string function(int cur) {
    string order = orders[cur];
    deque<int> dq = deques[cur];
    bool isReverse = false;
    for (int j = 0; j < order.size(); j++) {
        if (order[j] == 'R')
            isReverse = !isReverse;
        else {
            if (dq.empty())
                return "error";


            if (isReverse)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }

    string answer = "[";
    while (!dq.empty()) {
        if (isReverse) {
            answer += to_string(dq.back()) + ",";
            dq.pop_back();
        } else {
            answer += to_string(dq.front()) + ",";
            dq.pop_front();
        }
    }
    if (answer[answer.size() - 1] == ',')
        answer[answer.size() - 1] = ']';
    else
        answer += ']';
    return answer;
}

void solution() {
    for (int i = 0; i < orders.size(); i++) {
        oss << function(i) << '\n';
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
