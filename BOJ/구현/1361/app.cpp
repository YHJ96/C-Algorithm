#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int k = 0; k < n; k ++) {
        cin >> s;
        // 배열의 마지막 요소 비교를 위해 공백를 더해줌
        s += " ";
        bool ck = 1;
        int a[26];
        // 배열 초기화
        memset(a, 0, sizeof(a));
        // 요소 순회 시작
        for(int i = 0; i < s.size() - 1; i++) {
            // 연속하지 않은 다른 값이 나올 경우 인덱스에 자리에 더해줌
            if (s[i] != s[i + 1]) a[s[i] - 97] += 1;
        }
        // 중복으로 사용된 알파벳이 있는지 확인
        for(int i = 0; i < 26; i++) {
            if (a[i] > 1) ck = 0;
        }
        // 중복으로 사용한게 없다면 + 1
        if (ck) cnt++;
    }
    cout << cnt;
}