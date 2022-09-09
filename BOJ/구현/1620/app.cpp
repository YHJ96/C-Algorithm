#include <bits/stdc++.h>
using namespace std;
int n, m;
map <string, string> _map;
vector <string> v;
int main(void) {
    // freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // map을 이용해서 각각의 키와 값을 번호와 이름에 따라 부여한다.
        _map.insert({to_string(i+1), s});
        _map.insert({s, to_string(i+1)});
    }
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    // 출력하려는 키를 이용해서 값을 모두 출력한다.
    for(auto item: v) cout << _map[item] << "\n";
}