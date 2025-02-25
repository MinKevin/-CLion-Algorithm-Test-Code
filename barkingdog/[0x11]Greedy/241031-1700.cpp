#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> orders;
vector<int> multitab;
vector<bool> founded;
int answer;
void input() {
    cin >> N >> K;
    multitab = vector(N, 0);
    orders = vector(K, 0);
    founded = vector(N, false);
    answer = 0;

    for (int i = 0; i < K; i++) {
        cin >> orders[i];
    }
}

void solution() {
    for (int i = 0; i < orders.size(); i++) {
        bool foundEmptySpace = false;
        for (int j = 0; j < multitab.size(); j++) {
            if (multitab[j] == 0 || multitab[j] == orders[i]) {
                multitab[j] = orders[i];
                foundEmptySpace = true;
                break;
            }
        }

        if (!foundEmptySpace) {
            int counter = 0;
            founded = vector(N, false);
            for (int j = i + 1; j < orders.size(); j++) {
                if (counter == N - 1) {
                    break;
                }
                for (int k = 0; k < multitab.size(); k++) {
                    if (multitab[k] == orders[j] && !founded[k]) {
                        founded[k] = true;
                        counter++;
                        break;
                    }
                }
            }
            for (int j = 0; j < founded.size(); j++) {
                if (!founded[j]) {
                    multitab[j] = orders[i];
                    answer++;
                    break;
                }
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
