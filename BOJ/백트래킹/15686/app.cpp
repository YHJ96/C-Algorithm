#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[54][54];
vector<pair<int, int>> home, chicken;
vector<vector<int>> ret;
vector<int> v;
int ans = 987654321;

// 치킨 좌표 인덱스 조합 생성 함수
void combi(int num, vector<int> v) {
    if (v.size() == m) {
        ret.push_back(v);
        return;
    };

    for(int i = num; i < chicken.size(); i++) {
        // 좌표를 push
        v.push_back(i);
        combi(i + 1, v);
        // 좌표를 원상 복구
        v.pop_back();
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            // 치킨과 집의 좌표를 분리한다.
            if (a[i][j] == 1) home.push_back({ i, j });
            if (a[i][j] == 2) chicken.push_back({ i, j });
        }
    }
    // 치킨 좌표 생성
    combi(0, v);
    for(auto idx: ret) {
        int cnt = 0;
        for(auto homePos: home) {
            int _min = 987654321;
            for(auto ckPos: idx) {
                // 거리 공식
                int dist = abs(homePos.first - chicken[ckPos].first) + abs(homePos.second - chicken[ckPos].second);
                // 각 집에서 치킨의 최소 거리 정제
                _min = min(_min, dist);
            }
            // 해당 치킨 거리 더함
            cnt += _min;
        }
        // 최종 치킨 거리중에서 짧은 거리 확인
        ans = min(ans, cnt);
    }
    cout << ans;
}