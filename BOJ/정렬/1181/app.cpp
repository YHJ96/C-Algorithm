#include <bits/stdc++.h>
using namespace std;
vector<string> v;
set<string> _set;
int n;

// 커스텀 정렬 함수
bool custom(string a, string b) {
    // 길이가 같다면 사전 순서순
    if (a.size() == b.size()) return a < b;
    // 아니면 길이순 정렬
    else return a.size() < b.size();
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        _set.insert(s);
    }
    // 자료구조 set으로 중복 제거
    for(auto item: _set) {
        v.push_back(item);
    }
    // 커스텀 정렬 시작
    sort(v.begin(), v.end(), custom);

    for(auto item: v) cout << item << "\n";
}