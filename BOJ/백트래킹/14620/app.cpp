#include <bits/stdc++.h>
using namespace std;
int n;
int a[14][14];
int visited[14][14];
int dy[4] = {1, 0, -1, 0}; int dx[4] = {0, 1, 0, -1};
int _min = 987654321;

// 꽃을 심을수 있는지 확인하는 함수 생성
bool check(int y, int x) {
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 좌표가 벗어났거나 방문이 되어있으면 return 0
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) return 0;
        if (visited[ny][nx]) return 0;
    }
    // 위에서 정지하지 않으면 return 1
    return 1;
}
// 꽃을 심는 함수 생성 
int setFlower(int y, int x) {
    // 현재 좌표 초기화
    int price = a[y][x];
    // 현재 좌표 방문처리
    visited[y][x] = 1;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 4방 탐색한 좌표 방문 처리
        visited[ny][nx] = 1;
        // 4방 탐색한 좌표 총 금액 더하기
        price += a[ny][nx];
    }
    return price;
}
// 꽃을 제거하는 함수 생성
void deleteFlower(int y, int x) {
    // 현재 좌표 방문해제
    visited[y][x] = 0;
    // 4방 탐색 시작
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 4방 탐색한 좌표 방문 해제
        visited[ny][nx] = 0;
    }
} 
// 완전탐색 함수 생성 완료
void go(int cnt, int total) {
    // 꽃이 3개인 경우 정지
    if (cnt == 3) {
        // 현재 값과 가격을 비교해서 최소값 정제
        _min = min(_min, total);
        return;
    }
    // 백트래킹 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 꽃을 심을 수 있는 위치 확인
            if (check(i, j)) {
                // 개수와 가격을 정제
                go(cnt + 1, total + setFlower(i, j));
                // 꽃 제거 완료
                deleteFlower(i, j);
            }
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    // 완전 탐색 시작
    go(0, 0);
    cout << _min;
}