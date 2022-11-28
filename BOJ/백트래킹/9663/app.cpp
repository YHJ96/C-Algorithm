#include <bits/stdc++.h>
using namespace std;
int n;
int visited[20];
// 체스판을 체크하는 함수 생성
bool isCheck(int here) {
    for(int i = 0; i < here; i++) {
        if (visited[i] == visited[here]) return false;
        if (abs(visited[here] - visited[i]) == here - i) return false;
    }
    return true;
}

int go(int here) {
    int ret = 0;
    // 모든 열에 퀸이 있는 경우
    if (here == n) {
        return 1;
    } else {
        for(int i = 0; i < n; i++) {
            // row값 입력
            visited[here] = i;
            // 방문 체크
            if (isCheck(here)) ret += go(here + 1);
        }
    }
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << go(0);
}