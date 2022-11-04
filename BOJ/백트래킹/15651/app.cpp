#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[12];

void dfs(int depth) {
    // 해당 순열 출력
    if (depth == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    // 백트래킹 시작
    for(int i = 1; i <= n; i++) {
        // 중복 순열 생성
        a[depth] = i;
        dfs(depth + 1);
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dfs(0);
}