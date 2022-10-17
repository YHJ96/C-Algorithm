#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[1004];
map<int, int> _map;
map<int, int> _map_idx;
vector<pair<int, int>> v;
vector<int> ret;

// 커스텀 정렬 시작
bool custom(pair<int, int> a, pair<int, int> b) {
    // 빈도수가 같으면 처음 나온 순서대로 정렬
    if (a.second == b.second) return _map_idx[a.first] < _map_idx[b.first];
    return a.second > b.second;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // _map에 빈도수를 저장
        _map[a[i]]++;
        // _map_idx에 처음 나온 인덱스값을 저장
        if (!_map_idx[a[i]]) _map_idx[a[i]] = i + 1;
    }
    // v에 숫자와 해당 숫자의 빈도수를 초기화 
    for(auto item: _map) v.push_back({ item.first, item.second });
    // 커스텀 정렬 시작
    sort(v.begin(), v.end(), custom);
    // 출력 정제
    for(auto item: v) {
        for(int i = 0; i < item.second; i++) cout << item.first << " ";        
    }
}