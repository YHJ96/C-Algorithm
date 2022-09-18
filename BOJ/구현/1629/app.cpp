#include <bits/stdc++.h>
using namespace std;
long long a, b, c;

// 곱셉 정리 함수 생성 완료
long long func(long long a, long long b) {
    // base condition
    if (b == 1) return a % c;
    // 연산의 결과를 ret 기억
    long long ret = func(a, b / 2);
    // b / 2 * b / 2
    ret = (ret * ret) % c;
    // 홀수인 경우 a를 한번 곱하기
    if (b % 2 == 1) ret = (ret * a) % c;
    return ret;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    cout << func(a, b);
}