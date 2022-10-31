#include <bits/stdc++.h>
using namespace std;
string s;

// 20%
int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(getline(cin, s)) {
        stack<char> stk;
        bool flag = false;
        for(auto item: s) {
            if (item == ')') {
                if (stk.size() != 0 && stk.top() == '(') stk.pop();
                else flag = true;
            }

            if (item == ']') {
                if (stk.size() != 0 && stk.top() == '[') stk.pop();
                else flag = true;
            }

            if (item == '(' || item == '[') stk.push(item);
        }

        if (flag) {
            cout << "no" << "\n";
            continue;
        }

        if (stk.size() != 0) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }
}