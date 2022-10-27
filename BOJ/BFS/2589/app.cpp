#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[54][54];
int visited[54][54];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int ret = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    // 완전 탐색 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 바다 예외처리
            if (a[i][j] == 'W') continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            // 방문 시작
            visited[i][j] = 1;
            int _max = 0;
            while (q.size()) {
                int y, x;
                tie(y, x) = q.front(); q.pop();
                // 4방 탐색 시작
                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    // 좌표 예외처리
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    // 방문 예외처리
                    if (visited[ny][nx] != 0) continue;
                    // 바다 예외처리
                    if (a[ny][nx] == 'W') continue;
                    // 방문 진행
                    q.push({ny, nx});
                    // 최초 방문 설정
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
            // 최대값 추출
            for(int y = 0; y < n; y++) {
                for(int x = 0; x < m; x++) {
                    _max = max(_max, visited[y][x]);
                }
            }
            // 최대갑 정제
            ret = max(ret, _max);
            // 방문 초기화
            memset(visited, 0, sizeof(visited));
        }
    }
    cout << ret - 1;
}