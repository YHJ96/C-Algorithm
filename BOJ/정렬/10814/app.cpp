#include <bits/stdc++.h>
using namespace std;
int n, age;
string name;
vector<pair<int, string>> v;

// 커스텀 정렬 함수
bool custom(pair<int, string> a, pair<int, string> b) {
    // 첫 번째만 비교하고 나머지는 인덱싱 순서로 정렬
    return a.first < b.first;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> age >> name;
        v.push_back({ age, name });
    }
    // stable_sort && sort 비교 공부 필요
    stable_sort(v.begin(), v.end(), custom);

    for(auto item: v) {
        cout << item.first << " " << item.second << "\n";
    }
}