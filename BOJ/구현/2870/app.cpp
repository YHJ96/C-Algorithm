#include <bits/stdc++.h>
using namespace std;
int n;
string a[104];
vector<int> v;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // 런타임 에러 (out_of_range)
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        string s = a[i] + 'a';
        string t = "";
        for(int j = 0; j < s.size(); j++) {
            char c = s[j];
            if (97 <= c && c <= 122) {
                if (t == "") continue;
                // 이부분 문제인거 같다.
                // 직접 스트링 형식으로 구현해서 없애는 방법을 사용해야할꺼 같다.
                int num = stoi(t);
                v.push_back(num);
                t = "";
            } else {
                t += c;
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto item: v) cout << item << " ";
}