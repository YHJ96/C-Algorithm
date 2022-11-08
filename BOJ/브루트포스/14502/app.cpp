#include <bits/stdc++.h>
using namespace std;
int _max = 0;
int n, m;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int a[12][12];
int visited[12][12];
vector<pair <int, int>> v;
// 깊이 우선 탐색 실행 함수
void dfs(int y, int x) {
    visited[y][x] = 1;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        // 방문 예외처리
        if(a[ny][nx] == 1 || visited[ny][nx] == 1) continue;
        // 깊이 우선 탐색 시작
        dfs(ny, nx);
    }
}

int count() {
    int ret = 0;
    // 방문 초기화
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 바이러스이면 깊이 우선 탐색 실행
            if (a[i][j] == 2) dfs(i, j);
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 안전 영역 예외처리
            if (visited[i][j] || a[i][j] != 0) continue;
            ret++;
        }
    }
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            // 0인 좌표 입력
            if (a[i][j] == 0) v.push_back({ i, j });
        }
    }

    for(int i = 0; i < v.size() - 2; i++) {
        for(int j = i + 1; j < v.size() - 1; j++) {
            for(int k = j + 1; k < v.size(); k++) {
                int y1, y2, y3, x1, x2, x3;
                tie(y1, x1) = v[i];
                tie(y2, x2) = v[j];
                tie(y3, x3) = v[k];
                // 좌표 벽 세우기
                a[y1][x1] = 1;
                a[y2][x2] = 1;
                a[y3][x3] = 1;
                // 최대값 정제
                _max = max(_max, count());
                // 좌표 벽 해제 하기
                a[y1][x1] = 0;
                a[y2][x2] = 0;
                a[y3][x3] = 0;
            }
        }
    }
    cout << _max;
}