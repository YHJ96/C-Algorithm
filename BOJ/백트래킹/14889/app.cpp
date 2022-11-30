#include <bits/stdc++.h>
using namespace std;
int n;
int a[24][24];
int visited[24];
vector<int> v;
int _min = 987654321;

void combi(int num, int depth) {
    // n / 2의 인원을 뽑으면 정지
    if (depth == n / 2) {
        int t1 = 0, t2 = 0;
        // 완전 탐색 시작
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 현재 뽑은 인원의 점수를 측정
                if (visited[i] && visited[j]) t1 += a[i][j];
                // 뽑지 않은 인원의 점수를 측정 (다른 팀)
                if (!visited[i] && !visited[j]) t2 += a[i][j];
            }
        }
        // 팀의 능력치 최솟값 정제
        _min = min(_min, abs(t1 - t2));
        return;
    } else {
        // 백트래킹 시작
        for(int i = num; i < n; i++) {
            // 방문처리
            visited[i] = 1;
            // 다음 좌표 진행
            combi(i+1, depth+1);
            // 방문해제
            visited[i] = 0;
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
    combi(0, 0);
    cout << _min;
}