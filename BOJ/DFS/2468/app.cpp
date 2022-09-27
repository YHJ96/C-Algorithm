#include <bits/stdc++.h>
using namespace std;
int n;
int a[104][104];
int cpy[104][104];
int _max = 0;
int ans = 0;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int (&a)[104][104]) {
    a[y][x] = 0;
    for(int i  = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >=n || a[ny][nx] == 0) continue;
        dfs(ny, nx, a);
    }
}

// 미해결
int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        for(int j = 0; j < n; j++) {
            cin >> c;
            a[i][j] = (int)c - '0';
            _max = max(_max, a[i][j]);
        }
    }
    memcpy(cpy, a, sizeof(a));

    for(int k = 2; k < _max; k++) {
        int cnt;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (a[i][j] <= k) a[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (a[i][j] == 0) continue;
                cnt++;
                dfs(i, j, a);
            }
        }
        ans = max(cnt, ans);
        memcpy(a, cpy, sizeof(cpy));
        cnt = 0;
    }
    if (ans == 0) ans = 1;
    cout << ans;
}