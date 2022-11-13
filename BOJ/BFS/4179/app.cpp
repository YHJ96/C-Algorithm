#include <bits/stdc++.h>
using namespace std;
int n, m;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};
int ty, tx;
int ret = 0;
int fire_visited[1004][1004], person_visited[1004][1004];
char a[1004][1004];
queue<pair<int, int>> q;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 불이 없는 경우를 생각해서 최대의 값으로 초기화
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, 987654321);
    // 좌표 완전탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            // 불의 좌표를 queue에 push하고 방문처리
            if (a[i][j] == 'F') {
                q.push({ i, j });
                fire_visited[i][j] = 1;
            }
            // 현재 사람의 위치 저장
            if (a[i][j] == 'J') {
                ty = i;
                tx = j;
            }
        }
    }
    // 너비 우선 탐색 시작
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        // 4방 탐색 시작
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 좌표 예외처리
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 방문 예외처리
            if (fire_visited[ny][nx] != 987654321) continue;
            // 벽 예외처리
            if (a[ny][nx] == '#') continue;
            // 다음 좌표 + 1
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            // 다음 좌표 방문 진행
            q.push({ ny, nx });
        }
    }
    // 사람의 위치를 초기화
    q.push({ ty, tx });
    // 사람의 위치 방문처리
    person_visited[ty][tx] = 1;
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        // 가장자리의 좌표인지 확인
        if (y == n - 1 || x == m - 1 || y == 0 || x == 0) {
            ret = person_visited[y][x];
            break;
        }
        // 4방 탐색 시작
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 좌표 예외처리
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 방문 예외처리
            if (person_visited[ny][nx]) continue;
            // 벽 예외처리
            if (a[ny][nx] == '#') continue;
            // 불의 방문보다 사람의 방문 최소횟수가 같거나 크다면 이동 불가 예외처리
            if (fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
            // 다음 좌표 + 1
            person_visited[ny][nx] = person_visited[y][x] + 1;
            // 다음 좌표 방문 진행
            q.push({ ny, nx });
        }
    }
    // 분기 예외처리
    if (ret == 0) cout << "IMPOSSIBLE";
    else cout << ret;
}