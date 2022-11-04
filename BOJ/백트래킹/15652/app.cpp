#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[12];

void dfs(int num, int depth) {
    // 해당 중복 조합 출력
    if (depth == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    // 백트래킹 시작
    for(int i = num; i <= n; i++) {
        a[depth] = i;
        dfs(i, depth + 1);
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dfs(1, 0);
}