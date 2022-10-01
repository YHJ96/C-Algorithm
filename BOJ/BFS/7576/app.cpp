#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[1004][1004];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int y, x;
int _max;
bool zero;

int main(void) {
    freopen("./input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            // 해당 좌표가 1이면 큐에 등록한다.
            if (a[i][j] == 1) q.push({i, j});
        }
    }
    // 큐에 요소가 없을 때 까지 반복문 수행
    while(q.size()) {
        // 제일 첫 요소 꺼내기
        tie(y, x) = q.front(); q.pop();
        // 4방 탐색 시작
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 좌표 예외 처리
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 방문 예외 처리
            if (a[ny][nx] != 0) continue;
            // 횟수 저장
            a[ny][nx] = a[y][x] + 1;
            // 다음 좌표 방문
            q.push({ ny, nx });
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 제일 큰 수를 _max에 적립
            _max = max(_max, a[i][j]);
            // 요소가 0인지 확인
            if (a[i][j] == 0) zero = true;
        }
    }
    // zero가 ture이면 익지 않는 토마토가 존재 예외처리
    if (zero) cout << -1;
    // 1부터 시작함으로 - 1 처리 
    else cout << _max - 1;
}