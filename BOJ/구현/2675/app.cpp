#include <bits/stdc++.h>
using namespace std;
int t;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        string s, ret = "";
        cin >> n >> s;
        // 문자열의 요소만큼 순회 시작
        for(auto c: s) {
            // n - 1 만큼 문자열의 요소를 더해줌
            for(int j = 0; j < n; j++) {
                ret += c;
            }
        }
        cout << ret << "\n";
    }
}