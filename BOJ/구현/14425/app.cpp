#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
string a[10004];
map<string, int> _map;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
    }
    // 자료구조 map에 개수를 등록
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        _map[s]++;
    }
    // 자료구조 map에 있는 요소들의 개수를 더해줌
    for(int i = 0; i < n; i++) {
        ret += _map[a[i]];
    }

    cout << ret;
}