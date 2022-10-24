#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int> v[54];
int visited[54];
int cnt = 0;
int root;

void dfs(int node) {
    visited[node] = 1;
    if (v[node].size() == 1) cnt++;
    for(auto next: v[node]) {
        if (visited[next]) continue;
        dfs(next);
    }
}

// 78%
int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int node1 = i, node2; 
        cin >> node2;
        if (node2 == -1) {
            root = i;
            continue;
        }
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    cin >> t;
    visited[t] = 1;
    dfs(root);
    if (t == root) cout << 0;
    else cout << cnt;
}