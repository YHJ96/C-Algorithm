#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;
int visited[104][104];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

vector<vector<int>> maps = {
    {1,0,1,1,1},
    {1,0,1,0,1},
    {1,0,1,1,1},
    {1,1,1,0,1},
    {0,0,0,0,1}
};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    q.push({0, 0});
    visited[0][0] = 1;
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        // 4방 탐색 시작
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 방문 체크
            if (visited[ny][nx]) continue;
            // 벽을 체크
            if (maps[ny][nx] == 0) continue;
            // 방문 처리
            visited[ny][nx] = visited[y][x] + 1;
            // 다음 좌표 진행
            q.push({ ny, nx });
        }
    }
    
    if (visited[n - 1][m - 1]) return visited[n - 1][m - 1];
    return -1;
}

int main(void) {
    cout <<  solution(maps);
}