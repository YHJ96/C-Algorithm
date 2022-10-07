#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        // 백터에 요소들을 넣어줌
        v.push_back(item);
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());
    for(auto item: v) cout << item << "\n";
}