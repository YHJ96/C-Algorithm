#include <bits/stdc++.h>
using namespace std;
int n, k;
int ret = -10000000;
int sum[100004];

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    // 구간들의 합계 1부터 시작 했으므로 n도 포함
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        sum[i] = temp + sum[i-1];
    }
    // 전체 합에서 구하고자 하는 구간까지 전의 합을 뺴줌
    for(int i = k; i <= n; i++) {
        // 최대값 ret 할당
        ret = max(ret, sum[i] - sum[i-k]);
    }
    cout << ret;
}