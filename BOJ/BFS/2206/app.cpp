#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1004][1004];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int _min = 987654321;

// 24% fail
int bfs(int a[1004][1004], int y, int x) {
    a[y][x] = 0;
    queue<pair<int,int>> q;
    q.push({0, 0});
    a[0][0] = 2;

    while(q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] != 0) continue;
            a[ny][nx] = a[cy][cx] + 1;
            q.push({ ny, nx });
        }
    }
    if (a[n - 1][m - 1] == 0) return 1004;
    return a[n - 1][m - 1];
}

int main() {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            arr[i][j] = (int)s[j] - '0';
        }
    }

    _min = bfs(arr, 0, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] != 1) continue;
            _min = min(_min, bfs(arr, i, j));
        }
    }

    if (_min == 1004) cout << -1;
    else cout << _min - 1;
}