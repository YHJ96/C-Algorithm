#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int head = 1;
int cnt = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> t;
        // 상자의 공간을 위한 끝 점을 초기화
        int tail = head + (m - 1);
        // 상자의 구간에 있으면 continue
        if (head <= t && t <= tail) continue;
        // head가 t보다 크면 왼쪽으로 이동
        if (t < head) {
            int d = head - t;
            head -= d;
            cnt += d;
        // head가 t보다 작으면 오른쪽으로 이동    
        } else {
            int d = t - tail;
            head += d;
            cnt += d;
        }
    }
    cout << cnt;
}