#include <bits/stdc++.h>
using namespace std;
string a, b;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    // 문자열 a와 b를 뒤집기
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // int 형으로 정제한 후 대소 비교
    if (stoi(a) > stoi(b)) cout << a;
    else cout << b;
}