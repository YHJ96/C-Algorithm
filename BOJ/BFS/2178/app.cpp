#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100][100];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    a[y][x] = 2;
    // queue의 요소가 있으면 반복 수행
    while(q.size()) {
        // 제일 앞의 요소를 pos에 저장한뒤 제거
        pair<int, int> pos = q.front(); q.pop();
        // 4방 탐색
        for(int i = 0; i < 4; i++) {
            int ny = pos.first + dy[i];
            int nx = pos.second + dx[i];
            // 예외처리
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != 1) continue;
            // 방문처리
            a[ny][nx] = a[pos.first][pos.second] + 1;
            // 다음 좌표 진행
            q.push({ ny, nx });
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) a[i][j] = (int)s[j] - '0';
    }
    bfs(0, 0);
    // 초기값을 2로 설정하였으므로 - 1
    cout << a[n - 1][m - 1] - 1;
}