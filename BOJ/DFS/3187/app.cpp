#include <bits/stdc++.h>
using namespace std;
int n, m;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
char a[254][254];
int ret[2] = {0, 0};

// 깊이 우선 탐색 함수 생성
pair<int, int> dfs(int y, int x, int v, int k) {
    pair<int, int> ret = {0, 0};
    int cv = v;
    int ck = k;
    // 현재 좌표가 늑대인지 양인지 확인
    if (a[y][x] == 'v') cv++;
    if (a[y][x] == 'k') ck++;
    // 방문 처리
    a[y][x] = '#';
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 방문 예외 처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == '#') continue;
        int _v, _k;
        tie(_v, _k) = dfs(ny, nx, cv, ck);
        // 최대값 정제
        cv = max(cv, _v);
        ck = max(ck, _k);
    }
    // 양과 늑대를 개수를 더함
    ret.first += cv;
    ret.second += ck;
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (a[i][j] == '#') continue;;
            pair<int, int> cnt = dfs(i, j, 0, 0);
            // 양이 늑대 보다 많으면 늑대 삭제
            if (cnt.first < cnt.second) ret[1] += cnt.second;
            // 늑대가 양보다 많으면 양 삭제
            else ret[0] += cnt.first;
        }
    } 
    // 출력 정제
    cout << ret[1] << " " << ret[0];
}