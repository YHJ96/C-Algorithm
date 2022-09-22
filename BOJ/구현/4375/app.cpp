#include <bits/stdc++.h>
using namespace std;
int n;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n) {
        int ret = 1;
        int ans = 1;
        while(true) {
            if (ret % n == 0) {
                cout << ans << "\n";
                break;
            } else {
                // 1로만 이루어진 수를 만들기 위해 + 1
                ret = (ret * 10) + 1;
                // 모듈러 연산 (오버 플로우)
                ret %= n;
                ans++;
            }
        }
    }
}