#include <bits/stdc++.h>
using namespace std;
int n, m;
int visited[200004];
int cnt[200004];
queue<int> q;

int main() {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 현재위치와 탐색위치 예외처리
    if (n == m) {
        cout << 0 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    // 방문처리
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);

    while(q.size()) {
        int curr = q.front(); q.pop();
        for(auto next: { curr - 1, curr + 1, curr * 2 }) {
            // 범위 예외처리
            if (next < 0 || 200000 < next) continue;
            // 방문처리
            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[curr] + 1;
                cnt[next] += cnt[curr];
            // 이미 방문을 하였지만 다른 경우의 수 확인 
            } else if (visited[next] == visited[curr] + 1) {
                cnt[next] += cnt[curr];
            }
        }
    }
    cout << visited[m] - 1 << "\n";
    cout << cnt[m];
}