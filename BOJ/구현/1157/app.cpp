#include <bits/stdc++.h>
using namespace std;
string s;
int arr[26];
int _max = 0;
int cnt = 0;
char ret;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    // 문자열의 요소만큼 순회 시작
    for(int i = 0; i < s.size(); i++) {
        // 요소를 대문자로 변경
        char c  = toupper(s[i]);
        // 해당 인덱스에 개수 등록
        arr[c - 65]++;
        // 최대값 찾기
        _max = max(_max, arr[c - 65]);
    }
    // 중복된 요소가 있는지 확인
    for(int i = 0; i < 26; i++) {
        if (arr[i] == _max) {
            cnt++;
            ret = i + 65;
        }
    }
    // 예외처리
    if (cnt > 1) cout << '?';
    else cout << ret;
}