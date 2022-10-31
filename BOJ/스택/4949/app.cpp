#include <bits/stdc++.h>
using namespace std;
string s;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        getline(cin, s);
        if (s == ".") break;
        stack<char> stk;
        bool flag = false;
        // 문자열 탐색 시작
        for(auto item: s) {
            // 문자가 '('이거나 '['이면 스택에 push
            if (item == '(' || item == '[') stk.push(item);
            else {
                if (item == ')') {
                    // 괄호의 짝이 맞으면 pop
                    if (stk.size() != 0 && stk.top() == '(') stk.pop();
                    // 아닌 경우 정지
                    else {
                        flag = true;
                        break;
                    }
                }

                if (item == ']') {
                    // 괄호의 짝이 맞으면 pop
                    if (stk.size() != 0 && stk.top() == '[') stk.pop();
                    // 아닌 경우 정지
                    else {
                        flag = true;
                        break;
                    }
                }
            }
        }
        // 정지 예외처리
        if (flag) {
            cout << "no" << "\n";
            continue;
        }
        // 스택이 비어있으면 올바른 괄호이며 아닌 경우 no 출력
        if (stk.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}