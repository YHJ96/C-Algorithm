#include <bits/stdc++.h>
using namespace std;
int t, h, w;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int a[100][100];

// 깊이 우선 탐색 함수 생성
void dfs(int y, int x) {
    a[y][x] = 0;
    // 4방 탐색
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 예외 처리
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (a[ny][nx] != 1) continue;
        // 다음 좌표 방문
        dfs(ny, nx);
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int k = 0; k < t; k++)  {
        memset(a, 0, sizeof(a));
        string s;
        int cnt = 0;
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            cin >> s;
            for(int j = 0; j < w; j++) {
                if(s[j] == '#') a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        // 완전 탐색 시작
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                // 좌표가 1이라면 깊이 우선 탐색 시작
                if (a[i][j] != 1) continue;
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}