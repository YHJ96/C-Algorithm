#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200004];
int visited[200004];
queue<int> q;

int main() {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 현재위치와 탐색위치 예외처리
    if (n == m) {
        cout << 0;
        return 0;
    }
    // 방문처리
    visited[n] = 1;
    a[n] = 1;
    q.push(n);

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int next: { curr + 1, curr - 1, curr * 2 }) {
            // 최대 범위 예외처리
            if (next < 0 || next > 200000) continue;
            // 방문 예외처리
            if (visited[next]) continue;
            // 방문 처리
            visited[next] = 1;
            // 최초 방문 횟수
            a[next] = a[curr] + 1;
            // 다음 탐색 진행
            q.push(next);
        }
    }
    // 초기값이 1이므로 -1 정제
    cout << a[m] - 1;
}