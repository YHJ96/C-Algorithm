#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[104][104];
int visited[104][104];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int cnt1, cnt2;

void dfs(int y, int x) {
    // 방문처리
    visited[y][x] = 1;
    // 1 좌표를 만나면 벡터에  push 한 후에 정지
    if (a[y][x] == 1) return v.push_back({ y, x });
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        // 방문 예외처리
        if (visited[ny][nx] == 1) continue;
        // 탐색 시작
        dfs(ny, nx);
    }
};

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            // 총 치즈의 개수 초기화
            if (a[i][j] == 1) cnt2++;
        }
    }

    while(true) {
        bool flag = true;
        int cnt3 = 0;
        // 탐색 진행
        dfs(0, 0);
        // 치즈가 녹는 시간
        cnt1++;
        // 치즈 좌표 녹이기
        for(auto item: v) {
            int cy, cx;
            tie(cy, cx) = item;
            a[cy][cx] = 0;
            cnt3++;
        }
        // 초기화
        v.clear();
        memset(visited, 0, sizeof(visited));
        // 치즈 탐색 시작
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (a[i][j] == 1) flag = false;
            }
        }
        // 치즈가 없으면 정지
        if (flag) break;
        // 남은 치즈제거 완료
        else cnt2 -= cnt3;
    }

    cout << cnt1 << "\n";
    cout << cnt2;
}