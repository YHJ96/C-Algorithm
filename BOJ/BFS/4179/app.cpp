#include <bits/stdc++.h>
using namespace std;
int n, m;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};
int ty, tx;
int ret;
int fire_visited[1004][1004], person_visited[1004][1004];
char a[1004][1004];
queue<pair<int, int>> q;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 'F') {
                fire_visited[i][j] = 1;
                q.push({ i, j });
            }

            if (a[i][j] == 'J') {
                ty = i;
                tx = j;
            }
        }
    }

    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == '#') continue;
            if (fire_visited[ny][nx]) continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ ny, nx });   
        }
    }

    person_visited[ty][tx] = 1;
    q.push({ ty, tx });
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        
        if (y == n - 1 || x == m - 1 || y == 0 || x == 0) {
            ret = person_visited[y][x];
            break;
        }

        for(int i = 0 ; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == '#') continue;
            if (person_visited[ny][nx]) continue;
            if (fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
            person_visited[ny][nx] = person_visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    cout << ret;
}