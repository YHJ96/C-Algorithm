#include <bits/stdc++.h>
using namespace std;
int n;
int visited[12];
int a[12];

void permu(int depth) {
    if (depth == n) {
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    } 

    for(int i = 1; i <= n; i++) {
        // 방문 확인
        if (visited[i]) continue;
        // 방문 처리
        visited[i] = 1;
        // 순열 대입
        a[depth] = i;
        permu(depth + 1);
        // 방문 해제
        visited[i] = 0;
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // 순열 시작
    permu(0);
}