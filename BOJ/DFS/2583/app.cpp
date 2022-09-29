#include <bits/stdc++.h>
#define y1 y11
using namespace std;

int a[104][104], dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int m, n, k, x1, x2, y1, y2;
vector<int> v;

// 영역의 개수를 구하는 dfs
int dfs(int y, int x) {
    a[y][x] = 1;
    int cnt = 1;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 예외처리
        if (ny < 0 || nx < 0 || ny >= m || nx >= n || a[ny][nx] == 1) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                a[y][x] = 1;
            }
        }
    }
    // 2차원 배열 완전탐색 시작
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // 영역 넣기
            if(a[i][j] != 1) v.push_back(dfs(i, j));
        }
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());
    // 출력 정제
    cout << v.size() << "\n";
    for(auto item: v) cout << item << " ";
}
