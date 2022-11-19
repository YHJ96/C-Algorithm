#include <bits/stdc++.h>
using namespace std;
int n = 5;

int solution(int n) {
    int ans = 0;
    // 점프를 하는 순간은 홀수, 짝수로 나누어지는지 확인하여야 한다.
    while(n != 0) {
        // 짝수이면 나누기 2를 진행한다.
        if (n % 2 == 0) {
            n /= 2;
        // 홀수이면 한칸 전진하여 짝수로 만드는 로직을 생각하며 -1 진행
        } else {
            n--;
            // 점프하는 횟수 증가 완료
            ans++;
        }
    }
    return ans;
}

int main(void) {
    cout << solution(n);
}