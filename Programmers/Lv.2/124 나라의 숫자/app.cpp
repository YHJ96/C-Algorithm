#include <bits/stdc++.h>
using namespace std;
int n = 1;

// 미해결
string solution(int n) {
    string answer = "";
    while(n != 0) {
        if (n % 3 == 0) {
            answer += "4";
            n /= 3;
            n -= 1;
        } else {
            answer += to_string(n % 3);
            n /= 3;
        }
    }
    return answer;
}

int main(void) {
    cout << solution(n);
}