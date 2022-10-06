#include <bits/stdc++.h>
using namespace std;
char a[104][104];
int visited[104][104];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int n, cnt;
string s;
vector<int> ret;


// 깊이 우선 탐색 시작
void dfs(int y, int x, char target) {
    visited[y][x] = 1;
    // 4방 탐색
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        // 방문 예외처리
        if (visited[ny][nx] == 1) continue;
        // 같은 값인지 예외처리
        if (a[ny][nx] != target) continue;
        dfs(ny, nx, target);
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 방문을 안한 좌표면 깊이 우선 탐색 시작
            if (visited[i][j] != 0) continue;
            cnt++;
            dfs(i, j, a[i][j]); 
        }
    }
    ret.push_back(cnt);
    // cnt & visited 초기화
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    // 적록색맹 예외처리
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (a[i][j] == 'R') a[i][j] = 'G';
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (visited[i][j] != 0) continue;
            cnt++;
            dfs(i, j, a[i][j]);
        }
    }
    ret.push_back(cnt);
    for(auto item: ret) cout << item << " ";
}