#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[104][104];
char c;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            // 구름과 구름이 아닌 값을 초기화 한다.
            if (c == '.') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }
    // 완전 탐색 시작
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            /*
              해당 좌표의 구름이 존재하는지 확인하는 예외처리
              현재가 -1이면 구름이 없으며 다음 좌표가 -1이 아니면 구름이 먼저 진행중인 구간
            */
            if (a[i][j] != -1 && a[i][j+1] == -1) {
                a[i][j+1] = a[i][j] + 1;
            }
        }
    }
    // 출력 정제
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}