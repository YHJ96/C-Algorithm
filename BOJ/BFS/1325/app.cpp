#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[10004];
int visited[10004];
int ret[10004];

// 시간 초과
int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        v[node2].push_back(node1);
    }

    for(int i = 1; i <= n; i++) {
        queue<int> q;
        int cnt = 0;
        q.push(i);
        while(q.size()) {
            int current = q.front(); q.pop();
            visited[current] = 1;
            for(auto next: v[current]) {
                if(visited[next]) continue;
                cnt++;
                q.push(next);
            }
        }
        memset(visited, 0, sizeof(visited));
        ret[i] = cnt;
    }

    int max = *max_element(ret, ret+10004);
    for(int i = 0; i < 10004; i++) {
        if (ret[i] == max) cout << i << " ";
    }
}