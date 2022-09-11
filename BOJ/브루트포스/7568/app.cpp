#include <bits/stdc++.h>
using namespace std;
int n;
int a[200][2];
int ret[200];
int ans[200];

int main(void) {
    // freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];       
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            if (a[i][0] > a[j][0] && a[i][1] > a[j][1]) ret[i]++;
        }
    }
    for(int i = 0; i < n; i++) {
        ans[i]++;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if (ret[i] < ret[j]) ans[i]++;
        }
        cout << ans[i] << ' ';
    }
}