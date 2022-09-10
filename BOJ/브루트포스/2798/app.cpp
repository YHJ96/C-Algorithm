#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[104];
int ans = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 완전 탐색 시작
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                // 3개의 카드를 뽑아서 더한 변수 초기화
                int sum = a[i] + a[j] + a[k];
                // m을 넘지 않으면서 제일 큰 카드를 뽑으면 ans에 할당
                if (ans < sum && sum <= m) {
                    ans = sum;
                }
            }
        }
    }
    cout << ans;
}