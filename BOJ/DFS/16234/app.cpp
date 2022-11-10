#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int a[54][54], visited[54][54]; 
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair <int, int>> v;
int sum, cnt;

// 도시의 탐색 확인하는 함수
void dfs(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        // 방문 예외처리
        if (visited[ny][nx]) continue;
        // 계산을 위한 인구수 절대값
        int num = abs(a[y][x] - a[ny][nx]);
        // l이상 r이하이면 인구이동 가능한 도시
        if (num >= l && num <= r) {
            // 방문 처리
            visited[ny][nx] = 1;
            // 도시 좌표 생성
            v.push_back({ ny, nx });
            // 도시 인구수 합
            sum += a[ny][nx];
            // 다음 좌표 실행
            dfs(ny, nx);
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        bool flag = false;
        // 방문 초기화
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 방문한 도시 예외처리
                if (visited[i][j]) continue;
                // 백터 초기화
                v.clear();
                // 초기 방문 처리
                visited[i][j] = 1;
                // 초기 좌표 처리
                v.push_back({ i, j });
                // 초기 인구수 처리
                sum = a[i][j];
                // 깊이 우선 탐색 실행
                dfs(i, j);
                // 만약 좌표가 1이라면 인구이동 불가능으로 예외처리
                if (v.size() == 1) continue;
                // 좌표의 결과 처리
                for(auto axis: v) {
                    a[axis.first][axis.second] = sum / v.size();
                    flag = 1;
                }
            }
        }
        // 인구이동이 일어나지 않으면 반복문 탈출
        if (!flag) break;
        // 도시 인구 이동 증가
        cnt++;
    }
    cout << cnt;
}