#include <bits/stdc++.h>
using namespace std;
vector<string> v;
char a[5] = { 'a', 'e', 'i', 'o', 'u' };
string s;

// 모음이 하나인지 확인하는 함수 생성
bool ch1(string s) {
    bool ck = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < s.size(); j++) {
            if (s[j] == a[i]) return ck = 1;
        }
    }
    return ck;
}

// 모음과 자음이 연속으로 3개가 오는지 확인하는 함수 생성
bool ch2(string s) {
    bool ck = 1;
    if (s.size() < 3) return 1;
    for(int i = 0; i < s.size() - 2; i++) {
        auto ch1 = find(a, a+5, s[i]) == a+5;
        auto ch2 = find(a, a+5, s[i + 1]) == a+5;
        auto ch3 = find(a, a+5, s[i + 2]) == a+5;
        if (ch1 && ch2 && ch3) return 0;
        if (!(ch1 || ch2 || ch3)) return 0;
    }
    return ck;
}

// 같은 글자가 2개 이상 오는지 확인하는 함수 생성
bool ch3(string s) {
    bool ck = 1;
    if (s.size() < 2) return 1;
    for(int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'e' || s[i] == 'o') continue;
        if (s[i] == s[i + 1]) return 0;
    }
    return ck;
}

// 모든 경우의 수를 확인하는 함수 생성
bool isCheck(string s) {
    if (ch1(s) && ch2(s) && ch3(s)) return 1;
    else return 0;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> s) v.push_back(s);
    // end를 삭제해줌
    v.pop_back();
    // 벡터의 요소만큼 순회시작
    for(auto item: v) {
        // 출력 정제
        if (isCheck(item)) cout << "<" << item << ">" << " " << "is acceptable.";
        else cout << "<" << item << ">" << " " << "is not acceptable.";
        cout << "\n";
    }
}