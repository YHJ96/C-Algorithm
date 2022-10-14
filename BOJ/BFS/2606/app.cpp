#include <bits/stdc++.h>
using namespace std;
int k, n;
vector<int> v[104];
int visited[104];
queue<int> q;
int cnt = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    for(int i = 0; i < n; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        // 양방향 간선 그래프 등록 완료
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    // 자료구조 queue 초기화
    q.push(1);
    // 방문 처리
    visited[1] = 1;
    // queue의 요소가 없을 때 까지 진행
    while(q.size()) {
        int curr = q.front(); q.pop();
        // 노드 탐색 시작
        for(auto next: v[curr]) {
            // 방문 예외 처리
            if (visited[next]) continue;
            // 방문 처리
            visited[next] = 1;
            cnt++;
            // 다음 노드 방문
            q.push(next);
        }
    }
    cout << cnt;
}