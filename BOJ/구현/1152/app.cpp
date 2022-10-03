#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    // 마지막 글자가 공백이 아닌 경우 예외처리
    if (s[s.size() - 1] != ' ') cnt++;

    for(int i = 0; i < s.size() - 1; i++) {
        // 현재 글자가 공백이 아니며 다음 글자가 공백이면 단어이다.
        if (s[i] != ' ' && s[i + 1] == ' ') cnt++;
    }
    cout << cnt;
}