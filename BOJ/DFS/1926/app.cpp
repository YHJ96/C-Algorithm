#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[504][504];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int cnt = 0;
int _max = 0;

int dfs(int y, int x) {
    int ret = 1;
    // 방문 처리
    a[y][x] = 0;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 예외 처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 0) continue;
        // 구역 + 1
        ret += dfs(ny, nx);
    }
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 예외 처리
            if (a[i][j] == 0) continue;
            // 구역의 개수 추가
            cnt++;
            // 구역의 크기 비교
            _max = max(_max, dfs(i, j));
        }
    }
    // 출력 정제
    cout << cnt << "\n";
    cout << _max;
}