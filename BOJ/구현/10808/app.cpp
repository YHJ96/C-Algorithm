#include <bits/stdc++.h>
using namespace std;
string str;
int ret[26];

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for(auto c: str) {
        // 소문자만 해당되므로 'a'의 아스키 코드인 97를 빼준 값을 초기화
        int idx = c - 97;
        // ret의 idx를 +1 증가
        ret[idx]++;
    }
    // 요소들을 순회하면서 출력
    for(int i = 0; i < 26; i++) {
        cout << ret[i] << " ";
    }
}