#include<bits/stdc++.h>
using namespace std;
string s = ")()(";

bool solution(string s) {
    bool answer = true;
    stack<char> stk;
    for(auto item: s) {
        // '(' 기호이면 스택에 push
        if (item == '(') {
            stk.push('(');
        }
        // ')' 기호이면 예외처리 시작
        if (item == ')') {
            // 스택에 요소가 존재하고 제일 뒤에 있는 요소가 '('이면 스택에서 제거
            if (!stk.empty() && stk.top() == '(') stk.pop();
            // 만약 스택이 비어있으면 return false
            else if (stk.empty()) return false;
        }
    }
    // 스택에 요소가 있으면 return fasle
    if (stk.size()) return false;
    return answer;
}

int main(void) {
    cout << solution(s);
}