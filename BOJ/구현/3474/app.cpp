#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        int cnt1 = 0, cnt2 = 0;
        // 2의 총개수를 구하기
        for(int j = 2; j <= n; j *= 2) {
            cnt1 += n / j;
        }
        // 5의 총개수를 구하기
        for(int j = 5; j <= n; j *= 5) {
            cnt2 += n / j;
        }
        // 2 * 5는 결과는 10으로 10의 몇 승인지 구하기
        cout << min(cnt1, cnt2) << "\n";
    }
}