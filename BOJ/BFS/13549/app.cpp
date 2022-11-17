#include <bits/stdc++.h>
using namespace std;
int n, k;
queue<int> q;
int visited[100004];

// 미해결
int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        int here = q.front(); q.pop();
        
        if (k % here) {
            visited[k] = visited[here];
            break;
        }

        for(auto next: { here + 1, here - 1 }) {
            if (visited[next]) continue;
            if (next < 0 || next > 100000) continue;
            visited[next] = visited[here] + 1;
            q.push(next);
        }
    }

    cout << visited[k];
}