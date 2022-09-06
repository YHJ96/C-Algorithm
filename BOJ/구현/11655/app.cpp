#include <bits/stdc++.h>
using namespace std;
string s;
string ret;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    for(auto c: s) {
        // 아스키 코드가 알파벳 요소면 실행
        if (65 <= c && c <= 90 || 97 <= c && c <= 122) {
            // 대문자이면서 13을 더하면 90을 넘기는 경우
            if ((65 <= c && c <= 90) && c + 13 > 90) {
                // 요소의 초과한 분량을 구한뒤 c를 제일 앞 - 1로 초기화 한 뒤 더함
                int n = (c + 13) - 90;
                c = 64;
                c += n;
                ret += c;
            // 소문자이면서 13을 더하면 122를 넘기는 경우
            } else if ((97 <= c && c <= 122) && c + 13 > 122) {
                // 요소의 초과한 분량을 구한뒤 c를 제일 앞 - 1로 초기화 한 뒤 더함
                int n = (c + 13) - 122;
                c = 96;
                c += n; 
                ret += c;
            } else {
                ret += (c + 13);
            }
        } else {
            ret += c;
        }
    }
    cout << ret;
}