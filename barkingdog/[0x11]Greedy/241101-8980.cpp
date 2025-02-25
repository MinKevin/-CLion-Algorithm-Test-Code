#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>

using namespace std;

struct goodsInfo {
    int departure;
    int arrival;
    int count;
};

struct cmp {
    bool operator() (goodsInfo a, goodsInfo b) {
        return a.arrival != b.arrival
        ? a.arrival < b.arrival
        : a.departure < b.departure;
    }
};

int N, C, M;
vector<goodsInfo> goodsInfos;
int answer;
vector<int> goodsWeightForEachVillage;

void input() {
    cin >> N >> C >> M;
    answer = 0;
    goodsWeightForEachVillage = vector(N + 1, 0);

    int departure, arrival, count;
    for (int i = 0; i < M; i++) {
        cin >> departure >> arrival >> count;
        goodsInfos.push_back({departure, arrival, count});
    }
}

void solution() {
    sort(goodsInfos.begin(), goodsInfos.end(), cmp());

    for (int i = 0; i < M; i++) {
        int enableCapacity = 10001;
        for (int j = goodsInfos[i].departure; j < goodsInfos[i].arrival; j++) {
            enableCapacity = min(enableCapacity, C - goodsWeightForEachVillage[j]);
        }

        for (int j = goodsInfos[i].departure; j < goodsInfos[i].arrival; j++) {
            goodsWeightForEachVillage[j] += min(enableCapacity, goodsInfos[i].count);
        }
        answer += min(enableCapacity, goodsInfos[i].count);
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
