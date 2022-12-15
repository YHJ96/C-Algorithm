#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[12];
int visited[12];

void dfs(int depth) {
    // depth가 진행이 완료되면 종료
    if (depth == m) {
        vector<int> v;
        for(int i = 0; i < m; i++) {
            v.push_back(a[i]);
        }
        // 정렬 (오름차순)
        sort(v.begin(), v.end());
        for(auto item: v) {
            cout << item << " ";
        }
        cout << "\n";
        return;
    }
    // 백트래킹 시작
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        // 방문 처리
        visited[i] = 1;
        // 배열의 깊이에 해당 값 넣기
        a[depth] = i;
        // 다음 좌표 진행
        dfs(depth + 1);
        // 방문 해제
        visited[i] = 0;
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