#include <bits/stdc++.h>
using namespace std;
int n, target, root;
vector<int> v[54];

int dfs(int node) {
    int ret = 0;
    int child = 0;
    for(auto next: v[node]) {
        if (next == target) continue;
        ret += dfs(next);
        // 다음 좌표가 진행되면 child + 1
        child++;
    }
    // 해당 노드의 자식이 없으면 1 출력
    if (child == 0) return 1;
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // 트리 단방향 그래프 정제
    for(int i = 0; i < n; i++) {
        int node; cin >> node;
        if (node == -1) root = i;
        else v[node].push_back(i);
    }
    cin >> target;
    // 루트 노드 예외 처리
    if (root == target) cout << 0;
    else cout << dfs(root);
}