#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[10004];
int visited[10004];
int a[10004];
int _max = 0;

// 깊이 우선 탐색 함수 생성 완료
int dfs(int node) {
    int ret = 1;
    // 방문 처리
    visited[node] = 1;
    for(auto next: v[node]) {
        // 방문 예외 처리
        if (visited[next]) continue;
        // 다음 좌표 방문
        ret += dfs(next);
    }
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 단반향 간선 그래프
    for(int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        v[node2].push_back(node1);
    }

    for(int i = 1; i <= n; i++) {
        // 변수에 dfs의 값 할당
        int t =  dfs(i);
        // 큰 값 추출
        _max = max(_max, t);
        // 배열에 저장
        a[i] = t;
        // 방문 초기화
        memset(visited, 0, sizeof(visited));
    }
    // 출력 정제
    for(int i = 1; i <= n; i++) {
        if (a[i] == _max) cout << i << " ";
    }
}