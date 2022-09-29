#include<bits/stdc++.h>
using namespace std;   
int a[101][101], visited[101][101], n, ret = 1;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int d){
    visited[y][x] = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        // 좌표 예외 처리
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; 
        // 높은 영역 확인후 없애기
        if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d);
    }
    return;
} 
int main(){
    freopen("./input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int d = 1; d < 101; d++){
        // 모든 높이를 검색하기 위한 배열 초기화
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); 
        int cnt = 0;  
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // 높이가 높거나 방문하지 않았으면 안전영역 진행
                if(a[i][j] > d && !visited[i][j]) {
                    dfs(i, j, d);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret; 
}