#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int visited[1000004];

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    // 방문 좌표 초기화
    visited[s] = 1;
    // up, down 값 설정
    int pi[2] = { u, -d };
    while(q.size()) {
        int current = q.front(); q.pop();
        for(int i = 0; i < 2; i++) {
            int next = current + pi[i];
            // 1층 ~ f층 예외처리
            if (next <= 0 || next > f) continue;
            // 방문한 층 예외처리
            if (visited[next] != 0) continue;
            // 방문 처리
            visited[next] = visited[current] + 1;
            // 다음 좌표 진행
            q.push(next);
        }
    }
    // 출력 예외 처리
    if (visited[g]) cout << visited[g] - 1;
    else cout << "use the stairs";
}