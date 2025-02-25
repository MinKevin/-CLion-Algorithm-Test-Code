#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct uniqueCmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first == b.first;
    }
};

int M, N;
vector<vector<pair<int, int> > > planetSizes;
int answer;

void input() {
    cin >> M >> N;
    planetSizes = vector(M, vector<pair<int, int> >(N, {0, 0}));

    int planetSize;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> planetSize;
            planetSizes[i][j] = {planetSize, j};
        }
    }
}

void solution() {
    for (int i = 0; i < M; i++) {
        sort(planetSizes[i].begin(), planetSizes[i].end(), less());
        planetSizes[i].erase(unique(planetSizes[i].begin(), planetSizes[i].end(), uniqueCmp()), planetSizes[i].end());
    }

    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            bool findDifferent = false;
            if (planetSizes[i].size() != planetSizes[j].size()) {
                findDifferent = true;
            }

            else
                for (int k = 0; k < N; k++) {
                    if (planetSizes[i][k].second != planetSizes[j][k].second) {
                        findDifferent = true;
                        break;
                    }
                }
            if (!findDifferent)
                answer++;
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
