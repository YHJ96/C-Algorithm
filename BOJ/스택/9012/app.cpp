#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> stk;
        bool flag = false;

        for(char item: s) {
            // '(' 문자는 스택에 push
            if (item == '(') stk.push(item);
            // 스택에 요소가 없고 ')' 문자이면 정지
            else if (item == ')' && stk.size() == 0) {
                flag = true;
                break;
            }
            // 짝이 맞으면 제거
            else if (item == ')' && stk.top() == '(') stk.pop();
        }
        // 예외처리
        if (flag) {
            cout << "NO" << "\n";
            continue;
        }
        // 스택에 요소가 없으면 NO 있으면 YES 출력
        if (stk.size()) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}