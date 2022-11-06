#include <bits/stdc++.h>
using namespace std;
string s;
set<string> _set;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    // 문자열 탐색 시작
    for(int i = 0; i < s.size(); i++) {
        string word;
        for(int j = i; j < s.size(); j++) {
            // 부분 문자열을 생성하기 위해 한 문자씩 생성
            word += s[j];
            // 중복되는 문자열을 제거하기 위한 자료구조 set 사용
            _set.insert(word);
        }
    }
    cout << _set.size();
}