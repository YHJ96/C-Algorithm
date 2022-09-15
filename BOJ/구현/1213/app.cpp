#include <bits/stdc++.h>
using namespace std;
string s;
map<char, int> _map;
vector<char> v;
int ck = 0;
char target;
string ret;
string ans;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    // map에 문자의 개수를 등록
    for(auto c: s) _map[c]++;
    // map의 요소만큼 순회 시작
    for(auto item: _map) {
        // 해당 문자가 홀수이면 수행
        if (item.second % 2) {
            ck++;
            target = item.first;
        }
        // 문자열이 홀수가 2개 이상이면 팰린드롬이 불가능하다.
        if (ck > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    // 정렬을 위한 백터에 요소 등록
    for(auto item: _map) v.push_back(item.first);
    // 사전순 정렬
    sort(v.begin(), v.end());
    // 팰린드롬 정제 시작
    for(auto item: v) {
        int n = _map[item];
        // 앞부분만 정제하기 위해서 n의 절반만큼만 정제한다.
        for(int i = 0; i < n / 2; i++) {
            ret += item;
        }
    }
    // ans에 ret을 더해주고 ret을 뒤집는다.
    ans += ret;
    reverse(ret.begin(), ret.end());
    // 홀수 짝수를 체크하여 정답 정제
    if (ck) ans += (target + ret);
    else ans += ret;

    cout << ans;
}