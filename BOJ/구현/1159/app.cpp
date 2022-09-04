#include <bits/stdc++.h>
using namespace std;
int a[26]; 
int n;
bool ck = true;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string item;
        cin >> item;
        // 요소의 첫 번째 문자만 추출하여 - 97를 빼준 값을 인덱스로 사용하여 값을 누적
        a[item[0] - 97]++;
    }
    for(int i = 0; i < 26; i++) {
        // 해당 배열의 요소의 값이 5이상이면 char 타입으로 치환하여 출력
        if (a[i] >= 5) {
            cout << char(i + 97);
            // 전부 없는 경우를 위해 ck 변수를 false 처리
            ck = false;
        }
    }
    // 예외처리
    if (ck) cout << "PREDAJA";
}