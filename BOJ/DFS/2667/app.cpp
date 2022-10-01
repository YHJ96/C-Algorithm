#include <bits/stdc++.h>
using namespace std;
int n;
int a[30][30];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
vector<int> v;

// 영역의 개수를 구하는 dfs 생성
int dfs(int y, int x) {
    // 방문 처리
    a[y][x] = 0;
    int cnt = 1;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표 예외처리
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        // 방문 예외처리
        if (a[ny][nx] == 0) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = (int)s[j] - '0';
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 좌표가 1의 값이라면 깊이 우선 탐색 실행
            if (a[i][j] == 1) v.push_back(dfs(i, j));
        }
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());
    // 출력 정제
    cout << v.size() << "\n";
    for(auto item: v) cout << item << "\n";
}