#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, int> _map;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // 숫자를 map에 등록
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        _map[num] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        // 숫자가 map에 등록되어 있으면 1 아니면 0을 출력한다.
        if(_map[num] == 1) cout << 1 << " ";
        else cout << 0 << " ";
    }
}