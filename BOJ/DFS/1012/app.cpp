#include <bits/stdc++.h>
using namespace std;
int init;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

// 깊이 우선 탐색 함수 생성
void dfs(int y, int x, int n, int m, int (&a)[54][54]) {
    // 방문 처리
    a[y][x] = 0;
    // 4방 탐색
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 예외 처리
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != 1) continue;
        // 다음 좌표 방문
        dfs(ny, nx, n, m, a);
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> init;
    while(init--) {
        int n, m, k;
        int cnt = 0;
        int a[54][54];
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) {
            int y, x;
            cin >> y >> x;
            a[y][x] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != 1) continue;
                // 방문 처리 하면 cnt + 1
                cnt++;
                // 깊이 우선 탐색 실행
                dfs(i, j, n, m, a);
            }
        }
        cout << cnt << "\n";
    }
}