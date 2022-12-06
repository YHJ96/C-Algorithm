#include<bits/stdc++.h>
using namespace std;

int n = 3;

int solution(int n) {
    // base 값 설정 완료
    int a[100004] = {0, 1, 1 };
    // 다이나믹 프로그래밍 
    for(int i = 2; i <= 100004; i++) {
        a[i+1] = a[i-1] + a[i] % 1234567;
    }
    int answer = a[n];
    return answer;
}

int main(void) {
    cout << solution(n);
}