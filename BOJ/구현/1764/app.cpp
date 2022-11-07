#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, bool> _map;
vector<string> v;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // 사람을 등록한다.
    for(int i = 0; i < n; i++) {
        cin >> s;
        _map[s] = true;
    }

    for(int i = 0; i < m; i++) {
        cin >> s;
        // 등록이 안되어 있는 사람이면 continue로 예외처리
        if(!_map[s]) continue;
        // 등록되어 있는 사람을 벡터에 push
        v.push_back(s);
    }
    // 사전순 정렬
    sort(v.begin(), v.end());
    // 출력 정제
    cout << v.size() << "\n";
    for(auto item: v) {
        cout << item << "\n";
    }
}