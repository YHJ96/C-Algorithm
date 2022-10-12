#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
vector<pair<int, int>> v;

// 커스텀 정렬
bool custom(pair<int, int> a, pair<int, int> b) {
    // y좌표가 같으면 x 좌표 오름차순 정렬
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }
    // 커스텀 정렬 시작
    sort(v.begin(), v.end(), custom);

    for(auto item: v) {
        cout << item.first << " " << item.second;
        cout << '\n';
    }
}