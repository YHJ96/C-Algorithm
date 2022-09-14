#include <bits/stdc++.h>
using namespace std;
int n;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m;
        string s1, s2;
        map<string, int> _map;
        cin >> m;
        // 해당 입력값 만큼 순회 시작
        for(int j = 0; j < m; j++) {
            cin >> s1 >> s2;
            // Map에 옷의 종류를 등록
            _map[s2]++;
        }
        // cnt 변수 초기화
        int cnt = 1;
        for(auto item: _map) {
            // 경우의 수 계산을 위해 + 1 (없는 경우를 포함해야하기 때문)
            cnt *= item.second + 1;
        }
        // 옷을 안입는 경우는 없으므로 공집합을 경우의 수에서 제거
        cout << cnt - 1 << "\n";
    }
}