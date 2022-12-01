#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[20];
vector<char> v;
vector<string> ret;

// 모음과 자음의 개수를 비교하여 만드는 함수 생성
bool isCheck(string s) {
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    int cnt1 = 0, cnt2 = 0;
    for(char c: s) {
        // 모음이 라면 cnt1를 증가 자음이면 cnt2를 증가
        if (find(vowel, vowel + 5, c) != vowel + 5) cnt1++;
        else cnt2++;
    }
    // 모음이 1개 이상 자음이 2개이상이면 true 반환
    if (cnt1 >= 1 && cnt2 >= 2) return true;
    else return false;
}

// 조합을 만드는 함수 생성
void combi(int idx, vector<char> v) {
    // 벡터의 크기가 n인 경우 정지
    if (v.size() == n) {
        string s = "";
        // 문자 정렬
        sort(v.begin(), v.end());
        // 문자열로 정제
        for (auto item: v) {
            s += item;
        }
        // 모음과 자음의 조건을 만족하면 ret에 push
        if (isCheck(s)) ret.push_back(s);
        return;
    } else {
        // 백트래킹 시작
        for(int i = idx; i < m; i++) {
            v.push_back(a[i]);
            combi(i + 1, v);
            v.pop_back();
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    // 조합 생성
    combi(0, v);
    // 문자열 사전순 정렬
    sort(ret.begin(), ret.end());
    for(auto item: ret) {
        cout << item << "\n";
    }
}