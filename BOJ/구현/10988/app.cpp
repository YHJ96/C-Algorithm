#include <bits/stdc++.h>
using namespace std;
string str;
string ret;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    // 문자열을 반대 요소부터 순회시작
    for(int i = str.size() - 1; i >= 0 ; i--) {
        // ret에 문자 요소 더해줌
        ret += str[i];
    }
    // str과 ret이 같다면 팰린드롬 문자열이므로 1 출력 아닌 경우 0 출력
    if (str == ret) cout << 1;
    else cout << 0;
}