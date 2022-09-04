#include <bits/stdc++.h>
using namespace std;
int a[9];
int ret = 0;

int main() {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        // 요소의 값을 증가
        ret += a[i];
    }
    // 오름차순 정렬
    sort(a, a + 9);
    // 완전탐색 시작
    for(int i = 0; i < 8; i++) {
        for(int j = i + 1; j < 9; j++) {
            int add = a[i] + a[j];
            // 크기가 100이 아니라면 continue
            if (ret - add != 100) continue;
            for(int k = 0; k < 9; k++) {
                // 2개의 요소를 제외한 나머지 요소 출력
                if(k == i || k == j) continue;
                cout << a[k] << '\n';
            }
            // early return
            return 0;
        }
    }
}