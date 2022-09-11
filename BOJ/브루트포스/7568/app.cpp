#include <bits/stdc++.h>
using namespace std;
int n;
int a[54][2];
int ret[54];

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    // 완전탐색 시작
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++){
            // 완전탐색을 하면서 덩치가 작은 경우 해당되는 사람 + 1
            if (a[i][0] > a[j][0] && a[i][1] > a[j][1]) ret[j]++;
            if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) ret[i]++;
        }
    }

    for(int i = 0; i < n; i++) {
        // 등수 + 1 정제 
        cout << ret[i] + 1 << " ";
    }
}