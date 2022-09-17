#include <bits/stdc++.h>
using namespace std;
int n;
string a[104];
int ret = 0;


int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    // n만큼 반복문 실행
    for(int i = 0; i < n; i++) {
        stack<char> s;
        // stack 초기화
        s.push(a[i][0]);
        // 1번 째 인덱스 부터 순회 시작
        for(int j = 1; j < a[i].size(); j++) {
            char item = a[i][j];
            // 스택에 요소가 있으며 제일 위에 있는 요소가 현재 요소와 같으면 스택에서 제거
            if (s.size() && s.top() == item) s.pop();
            else s.push(item);
        }
        // 스택이 비어 있으면 ret 증가
        if (s.empty()) ret++;
    }
    cout << ret;
}