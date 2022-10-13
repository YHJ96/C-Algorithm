#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
char b[8][8];
char w[8][8];
char a[54][54];
int _min = 100000000;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    // 검은색 체스판 생성
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            // i와 j의 짝수와 홀수가 모두 일치하면 "B"
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) b[i][j] = 'B';
            else b[i][j] = 'W';
        }
    }

    // 흰색 체스판 생성
    for(int i = 0; i < 8; i++) {
        // i와 j의 짝수와 홀수가 모두 일치하면 "W"
        for(int j = 0; j < 8; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) w[i][j] = 'W';
            else w[i][j] = 'B';
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    // 완전 탐색 시작
    for(int y = 0; y + 8 <= n; y++) {
        for(int x = 0; x + 8 <= m; x++) {
            
            int bc = 0, wc = 0;
            // 체스판 오려내기
            for(int i = y; i < y + 8; i++) {
                for(int j = x; j < x + 8; j++) {
                    if (a[i][j] != b[i - y][j - x]) bc++;
                    if (a[i][j] != w[i - y][j - x]) wc++;
                }
            }
            // 최소값 추출
            int cnt = min(bc, wc);
            _min = min(cnt, _min);
        }
    }
    cout << _min;
}