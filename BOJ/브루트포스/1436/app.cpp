#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0, t = 666;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // 완전 탐색 시작
    while(true) {
        // 정수형을 문자열로 치환
        string s = to_string(t);
        // 숫자 + 1
        t++;
        // 666 이라는 숫자가 없으면 다음 숫자로 진행
        if (s.find("666") == string::npos) continue;
        // 666이라는 숫자가 있으면 1 증가 (전위 연산자 사용) 결과가 n이면 출력 후 정지
        if (++cnt == n) {
            cout << s;
            break;
        } 
    }
}