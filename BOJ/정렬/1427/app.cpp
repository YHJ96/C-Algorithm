#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    // int 형으로 정제 완료
    for(auto item: s) {
        int n = (int)item - '0';
        v.push_back(n);
    }
    // 오름차순 정렬
    sort(v.begin(), v.end(), greater<int>());
    for(auto item: v) cout << item;
}