#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<pair<int, int>> v;

// 커스텀 정렬 함수 생성
bool custom(pair<int, int> a, pair<int, int> b) {
    // a == b가 같으면 y의 숫자를 비교
   if (a.first == b.first) return a.second < b.second;
   return a.first < b.first; 
}

int main(void) {
    freopen("./input.txt", "r", stdin);
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
        cout << "\n";
    }
}