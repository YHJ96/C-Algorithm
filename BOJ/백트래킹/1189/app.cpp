#include <bits/stdc++.h>
using namespace std;
int r, c, k;
char a[30][30];
int visited[30][30];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

// 완전탐색 함수 생성 완료
int go(int y, int x) {
    int ret = 0;
    // 현재 좌표가 집인 경우 정지
    if (y == 0 && x == c - 1) {
        // 해당 값의 방문거리가 k랑 같은 경우 return 1
        if (k == visited[y][x]) return 1;
        // 해당 값의 방문거리가 k가 아닌 경우 retun 0
        return 0;
    }
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        // 방문 예외처리
        if (visited[ny][nx]) continue;
        // 못가는 길 예외처리
        if (a[ny][nx] == 'T') continue;
        // 방문 처리
        visited[ny][nx] = visited[y][x] + 1;
        // 다음 좌표 진행
        ret += go(ny, nx);
        // 방문 해제
        visited[ny][nx] = 0;
    }
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    // 처음 위치 방문처리
    visited[r - 1][0] = 1;
    // 탐색 시작
    cout << go(r - 1, 0);
}